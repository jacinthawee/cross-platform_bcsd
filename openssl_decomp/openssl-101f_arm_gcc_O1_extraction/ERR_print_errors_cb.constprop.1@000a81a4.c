
void ERR_print_errors_cb_constprop_1(BIO *param_1)

{
  ulong uVar1;
  size_t len;
  int iVar2;
  ulong e;
  char *pcVar3;
  char *local_113c;
  char *pcStack_1138;
  int local_1134;
  int local_1130;
  CRYPTO_THREADID CStack_112c;
  char acStack_1124 [256];
  char acStack_1024 [4096];
  int local_24;
  
  local_24 = __TMC_END__;
  CRYPTO_THREADID_current(&CStack_112c);
  uVar1 = CRYPTO_THREADID_hash(&CStack_112c);
  do {
    e = ERR_get_error_line_data(&local_113c,&local_1134,&pcStack_1138,&local_1130);
    if (e == 0) break;
    ERR_error_string_n(e,acStack_1124,0x100);
    pcVar3 = pcStack_1138;
    if (-1 < local_1130 << 0x1e) {
      pcVar3 = "";
    }
    BIO_snprintf(acStack_1024,0x1000,"%lu:%s:%s:%d:%s\n",uVar1,acStack_1124,local_113c,local_1134,
                 pcVar3);
    len = strlen(acStack_1024);
    iVar2 = BIO_write(param_1,acStack_1024,len);
  } while (0 < iVar2);
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

