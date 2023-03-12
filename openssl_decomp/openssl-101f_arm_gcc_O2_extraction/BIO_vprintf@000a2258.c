
/* WARNING: Removing unreachable block (ram,0x000a325e) */
/* WARNING: Removing unreachable block (ram,0x000a3264) */
/* WARNING: Removing unreachable block (ram,0x000a22ea) */
/* WARNING: Removing unreachable block (ram,0x000a2630) */

int BIO_vprintf(BIO *bio,char *format,va_list args)

{
  int iVar1;
  undefined *local_860;
  int local_85c;
  undefined *local_858;
  undefined auStack_82c [2048];
  int local_2c;
  
  local_860 = auStack_82c;
  local_2c = __TMC_END__;
  local_85c = 0x800;
  local_858 = (undefined *)0x0;
  CRYPTO_push_info_("doapr()","b_print.c",0x31a);
  if (*format != '\0') {
                    /* WARNING: Could not recover jumptable at 0x000a2348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)(&switchD_000a2348::switchdataD_000a234c +
                      (uint)switchD_000a2348::switchdataD_000a234c * 2))();
    return iVar1;
  }
  while (local_85c == 0) {
    if (local_858 == (undefined *)0x0) {
      local_858 = (undefined *)CRYPTO_malloc(0x400,"b_print.c",0x2e5);
      local_860 = (undefined *)0x0;
    }
    else {
      local_858 = (undefined *)CRYPTO_realloc(local_858,0x400,"b_print.c",0x2ed);
    }
    local_85c = 0x400;
  }
  if (local_860 == (undefined *)0x0) {
    *local_858 = 0;
  }
  else {
    *local_860 = 0;
  }
  if (local_858 == (undefined *)0x0) {
    iVar1 = BIO_write(bio,auStack_82c,0);
  }
  else {
    iVar1 = BIO_write(bio,local_858,0);
    CRYPTO_free(local_858);
  }
  CRYPTO_pop_info();
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

