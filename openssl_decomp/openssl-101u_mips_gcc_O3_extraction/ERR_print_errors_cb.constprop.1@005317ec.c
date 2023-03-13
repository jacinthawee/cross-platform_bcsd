
void ERR_print_errors_cb_constprop_1(BIO *param_1)

{
  int *piVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  BIO_METHOD *type;
  BIO *parg;
  BIO *pBVar5;
  BIO *a;
  char *buf;
  char *buf_00;
  _func_603 **data;
  char **data_00;
  BIO *buf_01;
  int *line;
  BIO *file;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  BIO *pBVar9;
  code *pcVar10;
  undefined auStack_1178 [16];
  BIO *local_1168;
  BIO_METHOD *local_1164;
  char *local_1160;
  _func_603 *local_115c;
  undefined *local_1158;
  char *local_1150;
  int *local_114c;
  undefined local_1144 [12];
  _func_603 *local_1138;
  undefined auStack_1134 [8];
  BIO aBStack_112c [4];
  char acStack_102c [4096];
  int local_2c;
  
  pBVar9 = (BIO *)(local_1144 + 8);
  file = (BIO *)local_1144;
  local_114c = (int *)PTR___stack_chk_guard_006a9ae8;
  buf_01 = aBStack_112c;
  data_00 = (char **)(local_1144 + 4);
  data = &local_1138;
  buf = acStack_102c;
  local_1158 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(auStack_1134);
  buf_00 = "%lu:%s:%s:%d:%s\n";
  piVar1 = (int *)(**(code **)(local_1158 + -0x695c))(auStack_1134);
  local_1150 = "-check_ss_sig";
  do {
    parg = file;
    uVar3 = ERR_get_error_line_data((char **)file,(int *)pBVar9,data_00,(int *)data);
    if (uVar3 == 0) break;
    ERR_error_string_n(uVar3,(char *)buf_01,0x100);
    local_115c = local_1144._4_4_;
    if (((uint)local_1138 & 2) == 0) {
      local_115c = (_func_603 *)(local_1150 + -0x7274);
    }
    local_1164 = local_1144._0_4_;
    local_1160 = local_1144._8_4_;
    local_1168 = buf_01;
    BIO_snprintf(buf,0x1000,"%lu:%s:%s:%d:%s\n",piVar1);
    iVar2 = (**(code **)(local_1158 + -0x53bc))(buf);
    parg = param_1;
    iVar2 = BIO_write(param_1,buf,iVar2);
  } while (0 < iVar2);
  if (local_2c == *local_114c) {
    return;
  }
  pcVar10 = ERR_print_errors_cb_constprop_0;
  (**(code **)(local_1158 + -0x5330))();
  puVar8 = auStack_1178;
  do {
    *(char **)(puVar8 + -0x28) = buf;
    a = (BIO *)(puVar8 + -0x1174);
    *(code **)(puVar8 + -4) = pcVar10;
    *(BIO **)(puVar8 + -8) = pBVar9;
    pBVar9 = (BIO *)(puVar8 + -0x1184);
    *(BIO **)(puVar8 + -0xc) = file;
    line = (int *)(puVar8 + -0x117c);
    *(undefined **)(puVar8 + -0x118c) = PTR___stack_chk_guard_006a9ae8;
    *(BIO **)(puVar8 + -0x10) = buf_01;
    *(char ***)(puVar8 + -0x14) = data_00;
    *(_func_603 ***)(puVar8 + -0x18) = data;
    *(BIO **)(puVar8 + -0x1c) = param_1;
    *(int **)(puVar8 + -0x20) = piVar1;
    *(undefined **)(puVar8 + -0x11a0) = &_gp;
    *(char **)(puVar8 + -0x24) = buf_00;
    *(undefined4 *)(puVar8 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8;
    (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(a);
    uVar4 = (**(code **)(*(int *)(puVar8 + -0x11a0) + -0x695c))(a);
    *(undefined4 *)(puVar8 + -0x1194) = uVar4;
    *(char **)(puVar8 + -0x1190) = "-check_ss_sig";
    do {
      pBVar5 = pBVar9;
      piVar1 = line;
      uVar3 = ERR_get_error_line_data
                        ((char **)pBVar9,line,(char **)(puVar8 + -0x1180),(int *)(puVar8 + -0x1178))
      ;
      puVar6 = *(undefined **)(puVar8 + -0x11a0);
      if (uVar3 == 0) break;
      ERR_error_string_n(uVar3,puVar8 + -0x112c,0x100);
      if ((*(uint *)(puVar8 + -0x1178) & 2) == 0) {
        iVar2 = *(int *)(puVar8 + -0x1190) + -0x7274;
      }
      else {
        iVar2 = *(int *)(puVar8 + -0x1180);
      }
      buf_00 = puVar8 + -0x102c;
      *(undefined4 *)(puVar8 + -0x11a8) = *(undefined4 *)(puVar8 + -0x117c);
      *(undefined4 *)(puVar8 + -0x11ac) = *(undefined4 *)(puVar8 + -0x1184);
      *(undefined **)(puVar8 + -0x11b0) = puVar8 + -0x112c;
      a = (BIO *)(puVar8 + -0x116c);
      *(int *)(puVar8 + -0x11a4) = iVar2;
      BIO_snprintf(buf_00,0x1000,"%lu:%s:%s:%d:%s\n",*(undefined4 *)(puVar8 + -0x1194));
      type = BIO_s_file();
      BIO_set(a,type);
      BIO_ctrl(a,0x6a,0,parg);
      pBVar5 = a;
      piVar1 = (int *)0x670dcc;
      iVar2 = BIO_printf(a,"%s",buf_00);
      puVar6 = *(undefined **)(puVar8 + -0x11a0);
    } while (0 < iVar2);
    if (*(int *)(puVar8 + -0x2c) == **(int **)(puVar8 + -0x118c)) {
      return;
    }
    pcVar10 = ERR_print_errors_cb;
    (**(code **)(puVar6 + -0x5330))();
    *(BIO **)(puVar8 + -0x11e8) = a;
    *(code **)(puVar8 + -0x11c4) = pcVar10;
    *(BIO **)(puVar8 + -0x11c8) = pBVar9;
    pBVar9 = (BIO *)(puVar8 + -0x2304);
    *(int **)(puVar8 + -0x11cc) = line;
    file = (BIO *)(puVar8 + -0x22ec);
    *(undefined **)(puVar8 + -0x230c) = PTR___stack_chk_guard_006a9ae8;
    *(undefined **)(puVar8 + -0x11d0) = puVar8 + -0x1180;
    buf_01 = (BIO *)(puVar8 + -0x21ec);
    *(BIO **)(puVar8 + -0x11d4) = parg;
    data_00 = (char **)(puVar8 + -0x22fc);
    *(undefined **)(puVar8 + -0x11d8) = puVar8 + -0x1178;
    data = (_func_603 **)(puVar8 + -0x2300);
    *(char **)(puVar8 + -0x11dc) = "%lu:%s:%s:%d:%s\n";
    param_1 = (BIO *)(puVar8 + -0x22f8);
    *(char **)(puVar8 + -0x11e0) = "%s";
    *(char **)(puVar8 + -0x11e4) = buf_00;
    *(undefined **)(puVar8 + -0x2320) = &_gp;
    *(BIO **)(puVar8 + -0x2314) = pBVar5;
    *(undefined4 *)(puVar8 + -0x11ec) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8;
    (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(puVar8 + -0x22f4);
    buf = "%lu:%s:%s:%d:%s\n";
    buf_00 = (char *)(**(code **)(*(int *)(puVar8 + -0x2320) + -0x695c))(puVar8 + -0x22f4);
    *(char **)(puVar8 + -0x2310) = "-check_ss_sig";
    do {
      parg = pBVar9;
      uVar3 = ERR_get_error_line_data((char **)pBVar9,(int *)data_00,(char **)data,(int *)param_1);
      puVar7 = *(undefined **)(puVar8 + -0x2320);
      if (uVar3 == 0) break;
      ERR_error_string_n(uVar3,(char *)file,0x100);
      if ((*(uint *)(puVar8 + -0x22f8) & 2) == 0) {
        iVar2 = *(int *)(puVar8 + -0x2310) + -0x7274;
      }
      else {
        iVar2 = *(int *)(puVar8 + -0x2300);
      }
      *(undefined4 *)(puVar8 + -0x232c) = *(undefined4 *)(puVar8 + -0x2304);
      *(undefined4 *)(puVar8 + -9000) = *(undefined4 *)(puVar8 + -0x22fc);
      *(int *)(puVar8 + -0x2324) = iVar2;
      *(BIO **)(puVar8 + -0x2330) = file;
      BIO_snprintf((char *)buf_01,0x1000,"%lu:%s:%s:%d:%s\n",buf_00);
      uVar4 = (**(code **)(*(int *)(puVar8 + -0x2320) + -0x53bc))(buf_01);
      parg = buf_01;
      iVar2 = (**(code **)(puVar8 + -0x2314))(buf_01,uVar4,piVar1);
      puVar7 = *(undefined **)(puVar8 + -0x2320);
    } while (0 < iVar2);
    if (*(int *)(puVar8 + -0x11ec) == **(int **)(puVar8 + -0x230c)) {
      return;
    }
    pcVar10 = ERR_print_errors_fp;
    (**(code **)(puVar7 + -0x5330))();
    puVar8 = puVar8 + -0x2340;
  } while( true );
}

