
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int OBJ_NAME_init(void)

{
  _LHASH *p_Var1;
  
  if (names_lh != (_LHASH *)0x0) {
    return 1;
  }
  CRYPTO_mem_ctrl(3);
  names_lh = lh_new(obj_name_LHASH_HASH + 1,(LHASH_COMP_FN_TYPE)&DAT_0006e2e1);
  CRYPTO_mem_ctrl(2);
  p_Var1 = names_lh;
  if (names_lh != (_LHASH *)0x0) {
    p_Var1 = (_LHASH *)0x1;
  }
  return (int)p_Var1;
}

