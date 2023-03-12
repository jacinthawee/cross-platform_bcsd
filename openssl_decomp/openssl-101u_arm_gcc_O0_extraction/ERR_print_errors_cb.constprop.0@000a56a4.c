
void ERR_print_errors_cb_constprop_0(void *param_1)

{
  ulong uVar1;
  BIO_METHOD *type;
  int iVar2;
  ulong e;
  char *pcVar3;
  char *local_117c;
  char *pcStack_1178;
  int local_1174;
  int local_1170;
  CRYPTO_THREADID CStack_116c;
  BIO BStack_1164;
  char acStack_1124 [256];
  char acStack_1024 [4096];
  int local_24;
  
  local_24 = __stack_chk_guard;
  CRYPTO_THREADID_current(&CStack_116c);
  uVar1 = CRYPTO_THREADID_hash(&CStack_116c);
  do {
    e = ERR_get_error_line_data(&local_117c,&local_1174,&pcStack_1178,&local_1170);
    if (e == 0) break;
    ERR_error_string_n(e,acStack_1124,0x100);
    pcVar3 = pcStack_1178;
    if (-1 < local_1170 << 0x1e) {
      pcVar3 = "";
    }
    BIO_snprintf(acStack_1024,0x1000,"%lu:%s:%s:%d:%s\n",uVar1,acStack_1124,local_117c,local_1174,
                 pcVar3);
    type = BIO_s_file();
    BIO_set(&BStack_1164,type);
    BIO_ctrl(&BStack_1164,0x6a,0,param_1);
    iVar2 = BIO_printf(&BStack_1164,"%s",acStack_1024);
  } while (0 < iVar2);
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

