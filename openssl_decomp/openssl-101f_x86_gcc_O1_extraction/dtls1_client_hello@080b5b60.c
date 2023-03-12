
undefined4 dtls1_client_hello(SSL *param_1)

{
  uchar *puVar1;
  char *pcVar2;
  SSL_SESSION *pSVar3;
  ssl3_state_st *psVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  stack_st_SSL_CIPHER *psVar8;
  int iVar9;
  undefined4 *puVar10;
  char *pcVar11;
  char *pcVar12;
  
  if (param_1->state != 0x1110) goto LAB_080b5b74;
  pcVar2 = param_1->init_buf->data;
  pSVar3 = param_1->session;
  if (((((pSVar3 == (SSL_SESSION *)0x0) || (pSVar3->ssl_version != param_1->version)) ||
       ((pSVar3->session_id_length == 0 && (*(int *)(pSVar3->krb5_client_princ + 0x54) == 0)))) ||
      (*(int *)(pSVar3->krb5_client_princ + 4) != 0)) &&
     (iVar7 = ssl_get_new_session(param_1,0), iVar7 == 0)) {
    return 0xffffffff;
  }
  iVar7 = 0;
  puVar1 = param_1->s3->client_random;
  if (param_1->s3->client_random[0] == '\0') {
    do {
      iVar7 = iVar7 + 1;
      if (puVar1[iVar7] != '\0') {
        if (iVar7 != 0x20) goto LAB_080b5bfb;
        break;
      }
    } while (iVar7 != 0x20);
    ssl_fill_hello_random(param_1,0,puVar1,0x20);
  }
LAB_080b5bfb:
  pcVar2[0xc] = (char)((uint)param_1->version >> 8);
  pcVar2[0xd] = (char)param_1->version;
  psVar4 = param_1->s3;
  param_1->first_packet = param_1->version;
  *(undefined4 *)(pcVar2 + 0xe) = *(undefined4 *)psVar4->client_random;
  *(undefined4 *)(pcVar2 + 0x12) = *(undefined4 *)(psVar4->client_random + 4);
  *(undefined4 *)(pcVar2 + 0x16) = *(undefined4 *)(psVar4->client_random + 8);
  *(undefined4 *)(pcVar2 + 0x1a) = *(undefined4 *)(psVar4->client_random + 0xc);
  *(undefined4 *)(pcVar2 + 0x1e) = *(undefined4 *)(psVar4->client_random + 0x10);
  *(undefined4 *)(pcVar2 + 0x22) = *(undefined4 *)(psVar4->client_random + 0x14);
  *(undefined4 *)(pcVar2 + 0x26) = *(undefined4 *)(psVar4->client_random + 0x18);
  *(undefined4 *)(pcVar2 + 0x2a) = *(undefined4 *)(psVar4->client_random + 0x1c);
  if (param_1->new_session == 0) {
    pcVar11 = pcVar2 + 0x2f;
    uVar5 = param_1->session->session_id_length;
    pcVar2[0x2e] = (char)uVar5;
    pcVar12 = pcVar11;
    if (uVar5 == 0) goto LAB_080b5c95;
    if (uVar5 < 0x21) {
      pcVar12 = pcVar11 + uVar5;
      memcpy(pcVar11,param_1->session->session_id,uVar5);
      goto LAB_080b5c95;
    }
    iVar7 = 0x346;
  }
  else {
    pcVar12 = pcVar2 + 0x2f;
    pcVar2[0x2e] = '\0';
LAB_080b5c95:
    uVar5 = param_1->d1->cookie_len;
    if (uVar5 < 0x101) {
      *pcVar12 = (char)uVar5;
      memcpy(pcVar12 + 1,param_1->d1->cookie,param_1->d1->cookie_len);
      pcVar12 = pcVar12 + 1 + param_1->d1->cookie_len;
      psVar8 = SSL_get_ciphers(param_1);
      iVar7 = ssl_cipher_list_to_bytes(param_1,psVar8,pcVar12 + 2,0);
      if (iVar7 == 0) {
        iVar7 = 0x35b;
        iVar9 = 0xb5;
        goto LAB_080b5e42;
      }
      pcVar12[1] = (char)iVar7;
      *pcVar12 = (char)((uint)iVar7 >> 8);
      if (*(_STACK **)(param_1->psk_server_callback + 0x98) == (_STACK *)0x0) {
        pcVar11 = pcVar12 + iVar7 + 3;
        pcVar12[iVar7 + 2] = '\x01';
      }
      else {
        iVar9 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
        pcVar11 = pcVar12 + iVar7 + 3;
        pcVar12[iVar7 + 2] = (char)iVar9 + '\x01';
        if (iVar9 != 0) {
          iVar7 = 0;
          do {
            puVar10 = (undefined4 *)
                      sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar7);
            pcVar11[iVar7] = (char)*puVar10;
            iVar7 = iVar7 + 1;
          } while (iVar9 != iVar7);
          pcVar11 = pcVar11 + iVar9;
        }
      }
      *pcVar11 = '\0';
      iVar7 = ssl_add_clienthello_tlsext(param_1,pcVar11 + 1,pcVar2 + 0x4000);
      if (iVar7 != 0) {
        dtls1_set_message_header
                  (param_1,pcVar2,1,iVar7 - (int)(pcVar2 + 0xc),0,iVar7 - (int)(pcVar2 + 0xc));
        param_1->state = 0x1111;
        param_1->init_num = iVar7 - (int)pcVar2;
        param_1->init_off = 0;
        dtls1_buffer_message(param_1,0);
LAB_080b5b74:
        uVar6 = dtls1_do_write(param_1,0x16);
        return uVar6;
      }
      iVar7 = 0x371;
    }
    else {
      iVar7 = 0x350;
    }
  }
  iVar9 = 0x44;
LAB_080b5e42:
  ERR_put_error(0x14,0xf8,iVar9,"d1_clnt.c",iVar7);
  return 0xffffffff;
}

