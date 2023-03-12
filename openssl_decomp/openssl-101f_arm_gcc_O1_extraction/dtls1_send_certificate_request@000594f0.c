
undefined4 dtls1_send_certificate_request(SSL *param_1)

{
  undefined4 uVar1;
  int iVar2;
  _STACK *p_Var3;
  int iVar4;
  X509_NAME *a;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  _STACK *p_Var11;
  BUF_MEM *str;
  uchar *puVar12;
  uint local_38;
  uchar *local_2c [2];
  
  if (param_1->state == 0x2160) {
    str = param_1->init_buf;
    pcVar6 = str->data;
    local_2c[0] = (uchar *)(pcVar6 + 0xd);
    iVar2 = ssl3_get_req_cert_type();
    pcVar6[0xc] = (char)iVar2;
    local_2c[0] = local_2c[0] + iVar2 + 2;
    p_Var3 = (_STACK *)SSL_get_client_CA_list(param_1);
    iVar10 = iVar2 + 3;
    p_Var11 = p_Var3;
    if (p_Var3 != (_STACK *)0x0) {
      local_38 = 0;
      iVar8 = 0;
      while( true ) {
        iVar9 = iVar10 + 0xc;
        iVar4 = sk_num(p_Var3);
        if (iVar4 <= iVar8) break;
        a = (X509_NAME *)sk_value(p_Var3,iVar8);
        iVar4 = i2d_X509_NAME(a,(uchar **)0x0);
        iVar5 = BUF_MEM_grow_clean(str,iVar9 + iVar4 + 2);
        if (iVar5 == 0) {
          ERR_put_error(0x14,0x104,7,"d1_srvr.c",0x5eb);
          return 0xffffffff;
        }
        pcVar6 = str->data;
        puVar12 = (uchar *)(pcVar6 + iVar9);
        if (param_1->references << 2 < 0) {
          local_2c[0] = puVar12;
          i2d_X509_NAME(a,local_2c);
          pcVar6[iVar9] = (char)((uint)(iVar4 + -2) >> 8);
          puVar12[1] = (uchar)(iVar4 + -2);
        }
        else {
          pcVar6[iVar9] = (char)((uint)iVar4 >> 8);
          puVar12[1] = (uchar)iVar4;
          iVar4 = iVar4 + 2;
          local_2c[0] = puVar12 + 2;
          i2d_X509_NAME(a,local_2c);
        }
        local_38 = local_38 + iVar4;
        iVar10 = iVar10 + iVar4;
        iVar8 = iVar8 + 1;
      }
      p_Var3 = (_STACK *)((local_38 << 0x10) >> 0x18);
      p_Var11 = (_STACK *)(local_38 & 0xff);
    }
    pcVar6 = str->data;
    pcVar6[iVar2 + 0xd] = (char)p_Var3;
    pcVar6[iVar2 + 0xe] = (char)p_Var11;
    pcVar7 = str->data;
    local_2c[0] = (uchar *)(pcVar6 + iVar2 + 0xf);
    pcVar7[2] = (char)((uint)iVar10 >> 8);
    *pcVar7 = '\r';
    pcVar7[3] = (char)iVar10;
    pcVar7[1] = (char)((uint)iVar10 >> 0x10);
    pcVar7[4] = (char)(param_1->d1->handshake_write_seq >> 8);
    pcVar7[5] = (char)param_1->d1->handshake_write_seq;
    pcVar6 = param_1->init_buf->data;
    param_1->d1->handshake_write_seq = param_1->d1->handshake_write_seq + 1;
    param_1->init_num = iVar10 + 0xc;
    param_1->init_off = 0;
    dtls1_set_message_header(param_1,pcVar6,0xd,iVar10,0,iVar10);
    dtls1_buffer_message(param_1,0);
    param_1->state = 0x2161;
  }
  uVar1 = dtls1_do_write(param_1,0x16);
  return uVar1;
}

