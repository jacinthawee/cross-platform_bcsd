
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int OBJ_NAME_init(void)

{
  if (names_lh != (_LHASH *)0x0) {
    return 1;
  }
  CRYPTO_mem_ctrl(3);
  names_lh = lh_new(obj_name_LHASH_HASH,obj_name_LHASH_COMP);
  CRYPTO_mem_ctrl(2);
  return (uint)(names_lh != (_LHASH *)0x0);
}

