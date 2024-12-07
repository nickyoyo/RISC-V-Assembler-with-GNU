/* ********************* OPIVI (Whole Vector Register Move) ********************** */
union clause ast = VMVRTYPE : (regidx, bits(5), regidx)

mapping clause encdec = VMVRTYPE(vs2, simm, vd) if haveVExt()
  <-> 0b100111 @ 0b1 @ vs2 @ simm @ 0b011 @ vd @ 0b1010111 if haveVExt()

function clause execute(VMVRTYPE(vs2, simm, vd)) = {
  let start_element = get_start_element();
  let SEW     = get_sew();
  let imm_val = unsigned(zero_extend(sizeof(xlen), simm));
  let EMUL    = imm_val + 1;

  if not(EMUL == 1 | EMUL == 2 | EMUL == 4 | EMUL == 8) then { handle_illegal(); return RETIRE_FAIL };

  let EMUL_pow = log2(EMUL);
  let num_elem = get_num_elem(EMUL_pow, SEW);
  let 'n = num_elem;
  let 'm = SEW;

  let vm_val  : vector('n, dec, bool)     = read_vmask(num_elem, 0b1, 0b00000);
  let vs2_val : vector('n, dec, bits('m)) = read_vreg(num_elem, SEW, EMUL_pow, vs2);
  let vd_val  : vector('n, dec, bits('m)) = read_vreg(num_elem, SEW, EMUL_pow, vd);
  result      : vector('n, dec, bits('m)) = undefined;

  foreach (i from 0 to (num_elem - 1)) {
    result[i] = if i < start_element then vd_val[i] else vs2_val[i]
  };

  write_vreg(num_elem, SEW, EMUL_pow, vd, result);
  vstart = zeros();
  RETIRE_SUCCESS
}

mapping simm_string : bits(5) <-> string = {
  0b00000 <-> "1",
  0b00001 <-> "2",
  0b00011 <-> "4",
  0b00111 <-> "8"
}

mapping clause assembly = VMVRTYPE(vs2, simm, vd)
  <-> "vmv" ^ simm_string(simm) ^ "r.v" ^ spc() ^ vreg_name(vd) ^ sep() ^ vreg_name(vs2)