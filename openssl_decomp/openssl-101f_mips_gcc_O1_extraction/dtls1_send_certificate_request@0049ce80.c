
undefined4 dtls1_send_certificate_request(SSL *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  stack_st_X509_NAME *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  char *pcVar10;
  int iVar11;
  BUF_MEM *pBVar12;
  uint uVar13;
  char *local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar13 = 0;
  if (param_1->state == 0x2160) {
    pBVar12 = param_1->init_buf;
    pcVar10 = pBVar12->data;
    local_30 = pcVar10 + 0xd;
    iVar4 = ssl3_get_req_cert_type(param_1,local_30);
    iVar7 = iVar4 + 3;
    pcVar10[0xc] = (char)iVar4;
    local_30 = local_30 + iVar4 + 2;
    psVar5 = SSL_get_client_CA_list(param_1);
    if (psVar5 == (stack_st_X509_NAME *)0x0) {
      cVar9 = '\0';
    }
    else {
      iVar11 = 0;
      iVar8 = (*(code *)PTR_sk_num_006a7f2c)(psVar5);
      if (0 < iVar8) {
        do {
          uVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar5,iVar11);
          iVar8 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(uVar3,0);
          iVar6 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(pBVar12,iVar8 + iVar7 + 0xc + 2);
          puVar1 = PTR_i2d_X509_NAME_006a87d8;
          if (iVar6 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x104,7,"d1_srvr.c",0x5eb);
            uVar3 = 0xffffffff;
            goto LAB_0049cef4;
          }
          pcVar10 = pBVar12->data + iVar7 + 0xc;
          if ((param_1->references & 0x20000000U) == 0) {
            *pcVar10 = (char)((uint)iVar8 >> 8);
            pcVar10[1] = (char)iVar8;
            local_30 = pcVar10 + 2;
            (*(code *)puVar1)(uVar3,&local_30);
            iVar8 = iVar8 + 2;
          }
          else {
            local_30 = pcVar10;
            (*(code *)PTR_i2d_X509_NAME_006a87d8)(uVar3,&local_30);
            pcVar10[1] = (char)(iVar8 + -2);
            *pcVar10 = (char)((uint)(iVar8 + -2) >> 8);
          }
          uVar13 = uVar13 + iVar8;
          iVar7 = iVar7 + iVar8;
          iVar11 = iVar11 + 1;
          iVar8 = (*(code *)PTR_sk_num_006a7f2c)(psVar5);
        } while (iVar11 < iVar8);
      }
      cVar9 = (char)(uVar13 >> 8);
      uVar13 = uVar13 & 0xff;
    }
    local_30 = pBVar12->data + iVar4 + 0xd;
    *local_30 = cVar9;
    local_30[1] = (char)uVar13;
    pcVar10 = pBVar12->data;
    local_30 = local_30 + 2;
    pcVar10[1] = (char)((uint)iVar7 >> 0x10);
    pcVar10[2] = (char)((uint)iVar7 >> 8);
    *pcVar10 = '\r';
    pcVar10[3] = (char)iVar7;
    pcVar10[4] = (char)(param_1->d1->handshake_write_seq >> 8);
    pcVar10[5] = (char)param_1->d1->handshake_write_seq;
    pcVar10 = param_1->init_buf->data;
    param_1->d1->handshake_write_seq = param_1->d1->handshake_write_seq + 1;
    param_1->init_num = iVar7 + 0xc;
    param_1->init_off = 0;
    dtls1_set_message_header(param_1,pcVar10,0xd,iVar7,0,iVar7);
    dtls1_buffer_message(param_1,0);
    param_1->state = 0x2161;
  }
  uVar3 = dtls1_do_write(param_1,0x16);
LAB_0049cef4:
  if (local_2c == *(int *)puVar2) {
    return uVar3;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(iVar4 + 0x34) == 0x2140) {
    iVar7 = ssl_get_server_send_cert();
    if ((iVar7 == 0) &&
       ((iVar8 = *(int *)(*(int *)(iVar4 + 0x58) + 0x344), *(int *)(iVar8 + 0xc) != 0x10 ||
        (*(int *)(iVar8 + 0x10) != 0x20)))) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x109,0x44,"d1_srvr.c",0x63a);
      return 0;
    }
    uVar3 = dtls1_output_cert_chain(iVar4,iVar7);
    *(undefined4 *)(iVar4 + 0x44) = uVar3;
    *(undefined4 *)(iVar4 + 0x48) = 0;
    *(undefined4 *)(iVar4 + 0x34) = 0x2141;
    dtls1_buffer_message(iVar4,0);
    uVar3 = dtls1_do_write(iVar4,0x16);
    return uVar3;
  }
  uVar3 = dtls1_do_write(iVar4,0x16);
  return uVar3;
}

