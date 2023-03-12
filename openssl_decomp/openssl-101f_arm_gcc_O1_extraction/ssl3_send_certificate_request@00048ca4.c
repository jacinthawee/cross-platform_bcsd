
undefined4 ssl3_send_certificate_request(SSL *param_1)

{
  undefined4 uVar1;
  int iVar2;
  _STACK *p_Var3;
  int iVar4;
  X509_NAME *a;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  _STACK *p_Var9;
  BUF_MEM *str;
  uchar *puVar10;
  uint local_38;
  int local_34;
  uchar *local_2c [2];
  
  if (param_1->state == 0x2160) {
    str = param_1->init_buf;
    pcVar6 = str->data;
    local_2c[0] = (uchar *)(pcVar6 + 5);
    iVar2 = ssl3_get_req_cert_type();
    local_34 = iVar2 + 1;
    pcVar6[4] = (char)iVar2;
    local_2c[0] = local_2c[0] + iVar2;
    if ((param_1->version >> 8 == 3) && (0x302 < param_1->version)) {
      iVar2 = tls12_get_req_sig_algs(param_1,local_2c[0] + 2);
      *local_2c[0] = (uchar)((uint)iVar2 >> 8);
      local_34 = local_34 + iVar2 + 2;
      local_2c[0][1] = (uchar)iVar2;
      local_2c[0] = local_2c[0] + iVar2 + 4;
    }
    local_2c[0] = local_2c[0] + 2;
    p_Var3 = (_STACK *)SSL_get_client_CA_list(param_1);
    iVar2 = local_34 + 2;
    p_Var9 = p_Var3;
    if (p_Var3 != (_STACK *)0x0) {
      local_38 = 0;
      iVar7 = 0;
      while( true ) {
        iVar8 = iVar2 + 4;
        iVar4 = sk_num(p_Var3);
        if (iVar4 <= iVar7) break;
        a = (X509_NAME *)sk_value(p_Var3,iVar7);
        iVar4 = i2d_X509_NAME(a,(uchar **)0x0);
        iVar5 = BUF_MEM_grow_clean(str,iVar8 + iVar4 + 2);
        if (iVar5 == 0) {
          ERR_put_error(0x14,0x96,7,"s3_srvr.c",0x811);
          return 0xffffffff;
        }
        pcVar6 = str->data;
        puVar10 = (uchar *)(pcVar6 + iVar8);
        if (param_1->references << 2 < 0) {
          local_2c[0] = puVar10;
          i2d_X509_NAME(a,local_2c);
          pcVar6[iVar8] = (char)((uint)(iVar4 + -2) >> 8);
          puVar10[1] = (uchar)(iVar4 + -2);
        }
        else {
          pcVar6[iVar8] = (char)((uint)iVar4 >> 8);
          puVar10[1] = (uchar)iVar4;
          iVar4 = iVar4 + 2;
          local_2c[0] = puVar10 + 2;
          i2d_X509_NAME(a,local_2c);
        }
        local_38 = local_38 + iVar4;
        iVar2 = iVar2 + iVar4;
        iVar7 = iVar7 + 1;
      }
      p_Var3 = (_STACK *)((local_38 << 0x10) >> 0x18);
      p_Var9 = (_STACK *)(local_38 & 0xff);
    }
    pcVar6 = str->data;
    pcVar6[local_34 + 4] = (char)p_Var3;
    pcVar6[local_34 + 5] = (char)p_Var9;
    pcVar6 = str->data;
    *pcVar6 = '\r';
    pcVar6[1] = (char)((uint)iVar2 >> 0x10);
    pcVar6[3] = (char)iVar2;
    pcVar6[2] = (char)((uint)iVar2 >> 8);
    param_1->init_num = iVar2 + 4;
    param_1->init_off = 0;
    pcVar6 = param_1->init_buf->data;
    pcVar6[iVar2 + 4] = '\x0e';
    pcVar6[iVar2 + 5] = '\0';
    pcVar6[iVar2 + 6] = '\0';
    local_2c[0] = (uchar *)(pcVar6 + iVar2 + 8);
    pcVar6[iVar2 + 7] = '\0';
    param_1->state = 0x2161;
    param_1->init_num = param_1->init_num + 4;
  }
  uVar1 = ssl3_do_write(param_1,0x16);
  return uVar1;
}

