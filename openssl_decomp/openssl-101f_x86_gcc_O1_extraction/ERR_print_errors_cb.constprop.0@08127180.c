
void __regparm3 ERR_print_errors_cb_constprop_0(void *param_1)

{
  ulong uVar1;
  char *pcVar2;
  BIO_METHOD *type;
  int iVar3;
  ulong e;
  int in_GS_OFFSET;
  char *local_1178;
  char *local_1174;
  int local_1170;
  byte local_116c;
  CRYPTO_THREADID local_1168;
  BIO local_1160;
  char local_1120 [256];
  char local_1020 [4096];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  CRYPTO_THREADID_current(&local_1168);
  uVar1 = CRYPTO_THREADID_hash(&local_1168);
  do {
    e = ERR_get_error_line_data(&local_1178,&local_1170,&local_1174,(int *)&local_116c);
    if (e == 0) break;
    ERR_error_string_n(e,local_1120,0x100);
    pcVar2 = "";
    if ((local_116c & 2) != 0) {
      pcVar2 = local_1174;
    }
    BIO_snprintf(local_1020,0x1000,"%lu:%s:%s:%d:%s\n",uVar1,local_1120,local_1178,local_1170,pcVar2
                );
    type = BIO_s_file();
    BIO_set(&local_1160,type);
    BIO_ctrl(&local_1160,0x6a,0,param_1);
    iVar3 = BIO_printf(&local_1160,"%s",local_1020);
  } while (0 < iVar3);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

