
undefined4 dtls1_send_certificate_request(SSL *param_1)

{
  ushort *puVar1;
  BUF_MEM *str;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  _STACK *p_Var7;
  int iVar8;
  X509_NAME *a;
  int iVar9;
  uchar *puVar10;
  int iVar11;
  int iVar12;
  int in_GS_OFFSET;
  int local_38;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1->state == 0x2160) {
    str = param_1->init_buf;
    pcVar2 = str->data;
    local_24 = (uchar *)(pcVar2 + 0xd);
    iVar6 = ssl3_get_req_cert_type(param_1,local_24);
    pcVar2[0xc] = (char)iVar6;
    iVar12 = iVar6 + 3;
    local_24 = local_24 + iVar6 + 2;
    p_Var7 = (_STACK *)SSL_get_client_CA_list(param_1);
    if (p_Var7 == (_STACK *)0x0) {
      local_38 = 0;
      cVar4 = '\0';
    }
    else {
      local_38 = 0;
      iVar11 = 0;
      while( true ) {
        iVar8 = sk_num(p_Var7);
        if (iVar8 <= iVar11) break;
        a = (X509_NAME *)sk_value(p_Var7,iVar11);
        iVar8 = i2d_X509_NAME(a,(uchar **)0x0);
        iVar9 = BUF_MEM_grow_clean(str,iVar8 + 2 + iVar12 + 0xc);
        if (iVar9 == 0) {
          ERR_put_error(0x14,0x104,7,"d1_srvr.c",0x5eb);
          uVar5 = 0xffffffff;
          goto LAB_080b44ee;
        }
        puVar10 = (uchar *)(str->data + iVar12 + 0xc);
        if ((*(byte *)((int)&param_1->references + 3) & 0x20) == 0) {
          *puVar10 = (uchar)((uint)iVar8 >> 8);
          puVar10[1] = (uchar)iVar8;
          local_24 = puVar10 + 2;
          iVar8 = iVar8 + 2;
          i2d_X509_NAME(a,&local_24);
        }
        else {
          local_24 = puVar10;
          i2d_X509_NAME(a,&local_24);
          puVar10[1] = (uchar)(iVar8 + -2);
          *puVar10 = (uchar)((uint)(iVar8 + -2) >> 8);
        }
        local_38 = local_38 + iVar8;
        iVar12 = iVar12 + iVar8;
        iVar11 = iVar11 + 1;
      }
      cVar4 = (char)((uint)local_38 >> 8);
    }
    pcVar2 = str->data + iVar6 + 0xd;
    *pcVar2 = cVar4;
    pcVar2[1] = (char)local_38;
    pcVar3 = str->data;
    local_24 = (uchar *)(pcVar2 + 2);
    pcVar3[1] = (char)((uint)iVar12 >> 0x10);
    pcVar3[3] = (char)iVar12;
    *pcVar3 = '\r';
    pcVar3[2] = (char)((uint)iVar12 >> 8);
    pcVar3[4] = *(char *)((int)&param_1->d1->handshake_write_seq + 1);
    pcVar3[5] = (char)param_1->d1->handshake_write_seq;
    puVar1 = &param_1->d1->handshake_write_seq;
    *puVar1 = *puVar1 + 1;
    param_1->init_off = 0;
    param_1->init_num = iVar12 + 0xc;
    dtls1_set_message_header(param_1,param_1->init_buf->data,0xd,iVar12,0,iVar12);
    dtls1_buffer_message(param_1,0);
    param_1->state = 0x2161;
  }
  uVar5 = dtls1_do_write(param_1,0x16);
LAB_080b44ee:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

