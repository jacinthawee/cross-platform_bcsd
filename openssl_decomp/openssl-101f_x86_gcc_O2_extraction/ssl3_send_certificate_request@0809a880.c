
undefined4 ssl3_send_certificate_request(SSL *param_1)

{
  BUF_MEM *str;
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  _STACK *p_Var4;
  int iVar5;
  X509_NAME *a;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  char *pcVar9;
  int in_GS_OFFSET;
  int local_38;
  int local_30;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1->state == 0x2160) {
    str = param_1->init_buf;
    pcVar9 = str->data;
    local_24 = (uchar *)(pcVar9 + 5);
    iVar3 = ssl3_get_req_cert_type(param_1,local_24);
    pcVar9[4] = (char)iVar3;
    local_24 = local_24 + iVar3;
    local_30 = iVar3 + 1;
    if ((param_1->version >> 8 == 3) && (0x302 < param_1->version)) {
      local_30 = tls12_get_req_sig_algs(param_1,local_24 + 2);
      *local_24 = (uchar)((uint)local_30 >> 8);
      local_24[1] = (uchar)local_30;
      local_24 = local_24 + local_30 + 4;
      local_30 = iVar3 + 3 + local_30;
    }
    local_24 = local_24 + 2;
    iVar3 = local_30 + 2;
    p_Var4 = (_STACK *)SSL_get_client_CA_list(param_1);
    if (p_Var4 == (_STACK *)0x0) {
      local_38 = 0;
      cVar1 = '\0';
    }
    else {
      local_38 = 0;
      iVar8 = 0;
      while( true ) {
        iVar5 = sk_num(p_Var4);
        if (iVar5 <= iVar8) break;
        a = (X509_NAME *)sk_value(p_Var4,iVar8);
        iVar5 = i2d_X509_NAME(a,(uchar **)0x0);
        iVar6 = BUF_MEM_grow_clean(str,iVar5 + 2 + iVar3 + 4);
        if (iVar6 == 0) {
          ERR_put_error(0x14,0x96,7,"s3_srvr.c",0x811);
          uVar2 = 0xffffffff;
          goto LAB_0809a8ae;
        }
        puVar7 = (uchar *)(str->data + iVar3 + 4);
        if ((*(byte *)((int)&param_1->references + 3) & 0x20) == 0) {
          *puVar7 = (uchar)((uint)iVar5 >> 8);
          puVar7[1] = (uchar)iVar5;
          local_24 = puVar7 + 2;
          iVar5 = iVar5 + 2;
          i2d_X509_NAME(a,&local_24);
        }
        else {
          local_24 = puVar7;
          i2d_X509_NAME(a,&local_24);
          puVar7[1] = (uchar)(iVar5 + -2);
          *puVar7 = (uchar)((uint)(iVar5 + -2) >> 8);
        }
        local_38 = local_38 + iVar5;
        iVar3 = iVar3 + iVar5;
        iVar8 = iVar8 + 1;
      }
      cVar1 = (char)((uint)local_38 >> 8);
    }
    pcVar9 = str->data;
    pcVar9[local_30 + 4] = cVar1;
    (pcVar9 + local_30 + 4)[1] = (char)local_38;
    pcVar9 = str->data;
    pcVar9[1] = (char)((uint)iVar3 >> 0x10);
    *pcVar9 = '\r';
    pcVar9[3] = (char)iVar3;
    pcVar9[2] = (char)((uint)iVar3 >> 8);
    param_1->init_num = iVar3 + 4;
    param_1->init_off = 0;
    pcVar9 = param_1->init_buf->data + iVar3 + 4;
    *pcVar9 = '\x0e';
    pcVar9[1] = '\0';
    pcVar9[2] = '\0';
    local_24 = (uchar *)(pcVar9 + 4);
    pcVar9[3] = '\0';
    param_1->state = 0x2161;
    param_1->init_num = param_1->init_num + 4;
  }
  uVar2 = ssl3_do_write(param_1,0x16);
LAB_0809a8ae:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

