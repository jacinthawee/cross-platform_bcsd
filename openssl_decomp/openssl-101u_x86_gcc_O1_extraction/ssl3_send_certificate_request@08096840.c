
undefined4 ssl3_send_certificate_request(SSL *param_1)

{
  BUF_MEM *str;
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  _STACK *p_Var5;
  int iVar6;
  X509_NAME *a;
  int iVar7;
  char *pcVar8;
  uchar *puVar9;
  int iVar10;
  int in_GS_OFFSET;
  int local_34;
  int local_30;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1->state == 0x2160) {
    str = param_1->init_buf;
    pcVar8 = str->data;
    local_24 = (uchar *)(pcVar8 + 5);
    iVar4 = ssl3_get_req_cert_type(param_1,local_24);
    pcVar8[4] = (char)iVar4;
    local_24 = local_24 + iVar4;
    local_30 = iVar4 + 1;
    if ((param_1->version >> 8 == 3) && (0x302 < param_1->version)) {
      local_30 = tls12_get_req_sig_algs(param_1,local_24 + 2);
      *local_24 = (uchar)((uint)local_30 >> 8);
      local_24[1] = (uchar)local_30;
      local_24 = local_24 + local_30 + 4;
      local_30 = iVar4 + 3 + local_30;
    }
    local_24 = local_24 + 2;
    iVar4 = local_30 + 2;
    p_Var5 = (_STACK *)SSL_get_client_CA_list(param_1);
    if (p_Var5 == (_STACK *)0x0) {
      local_34 = 0;
      cVar2 = '\0';
    }
    else {
      local_34 = 0;
      iVar10 = 0;
      while( true ) {
        iVar6 = sk_num(p_Var5);
        if (iVar6 <= iVar10) break;
        a = (X509_NAME *)sk_value(p_Var5,iVar10);
        iVar6 = i2d_X509_NAME(a,(uchar **)0x0);
        iVar7 = BUF_MEM_grow_clean(str,iVar6 + 2 + iVar4 + 4);
        if (iVar7 == 0) {
          iVar4 = 0x845;
          goto LAB_08096abc;
        }
        puVar9 = (uchar *)(str->data + iVar4 + 4);
        if ((*(byte *)((int)&param_1->references + 3) & 0x20) == 0) {
          *puVar9 = (uchar)((uint)iVar6 >> 8);
          puVar9[1] = (uchar)iVar6;
          local_24 = puVar9 + 2;
          iVar6 = iVar6 + 2;
          i2d_X509_NAME(a,&local_24);
        }
        else {
          local_24 = puVar9;
          i2d_X509_NAME(a,&local_24);
          puVar9[1] = (uchar)(iVar6 + -2);
          *puVar9 = (uchar)((uint)(iVar6 + -2) >> 8);
        }
        local_34 = local_34 + iVar6;
        iVar4 = iVar4 + iVar6;
        iVar10 = iVar10 + 1;
      }
      cVar2 = (char)((uint)local_34 >> 8);
    }
    pcVar8 = str->data + local_30 + 4;
    *pcVar8 = cVar2;
    pcVar8[1] = (char)local_34;
    pcVar1 = str->data;
    local_24 = (uchar *)(pcVar8 + 2);
    pcVar1[1] = (char)((uint)iVar4 >> 0x10);
    *pcVar1 = '\r';
    pcVar1[3] = (char)iVar4;
    pcVar1[2] = (char)((uint)iVar4 >> 8);
    param_1->init_off = 0;
    param_1->init_num = iVar4 + 4;
    iVar4 = BUF_MEM_grow_clean(str,iVar4 + 8);
    if (iVar4 == 0) {
      iVar4 = 0x869;
LAB_08096abc:
      ERR_put_error(0x14,0x96,7,"s3_srvr.c",iVar4);
      param_1->state = 5;
      uVar3 = 0xffffffff;
      goto LAB_0809686e;
    }
    pcVar8 = param_1->init_buf->data + param_1->init_num;
    *pcVar8 = '\x0e';
    pcVar8[1] = '\0';
    pcVar8[2] = '\0';
    local_24 = (uchar *)(pcVar8 + 4);
    pcVar8[3] = '\0';
    param_1->state = 0x2161;
    param_1->init_num = param_1->init_num + 4;
  }
  uVar3 = ssl3_do_write(param_1,0x16);
LAB_0809686e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

