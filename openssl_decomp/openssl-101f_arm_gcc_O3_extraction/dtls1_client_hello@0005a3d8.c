
undefined4 dtls1_client_hello(SSL *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uchar *puVar3;
  stack_st_SSL_CIPHER *psVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uchar *puVar8;
  SSL_SESSION *pSVar9;
  uint uVar10;
  ssl3_state_st *psVar11;
  undefined4 uVar12;
  char *pcVar13;
  char *pcVar14;
  int iVar15;
  char *pcVar16;
  
  pcVar16 = param_1->init_buf->data;
  if (param_1->state != 0x1110) {
LAB_0005a3ee:
    uVar1 = dtls1_do_write(param_1,0x16);
    return uVar1;
  }
  pSVar9 = param_1->session;
  if (((((pSVar9 == (SSL_SESSION *)0x0) || (pSVar9->ssl_version != param_1->version)) ||
       ((pSVar9->session_id_length == 0 && (*(int *)(pSVar9->krb5_client_princ + 0x54) == 0)))) ||
      (*(int *)(pSVar9->krb5_client_princ + 4) != 0)) &&
     (iVar2 = ssl_get_new_session(param_1,0), iVar2 == 0)) {
    return 0xffffffff;
  }
  puVar8 = param_1->s3->client_random;
  uVar10 = (uint)param_1->s3->client_random[0];
  puVar3 = puVar8;
  if (uVar10 == 0) {
    do {
      puVar3 = puVar3 + 1;
      uVar10 = uVar10 + 1;
      if (*puVar3 != '\0') {
        if (uVar10 != 0x20) goto LAB_0005a440;
        break;
      }
    } while (uVar10 != 0x20);
    ssl_fill_hello_random(param_1,0,puVar8,0x20);
  }
LAB_0005a440:
  pcVar16[0xc] = (char)((uint)param_1->version >> 8);
  pcVar16[0xd] = (char)param_1->version;
  psVar11 = param_1->s3;
  param_1->first_packet = param_1->version;
  uVar12 = *(undefined4 *)(psVar11->client_random + 4);
  uVar1 = *(undefined4 *)(psVar11->client_random + 8);
  uVar7 = *(undefined4 *)(psVar11->client_random + 0xc);
  *(undefined4 *)(pcVar16 + 0xe) = *(undefined4 *)psVar11->client_random;
  *(undefined4 *)(pcVar16 + 0x12) = uVar12;
  *(undefined4 *)(pcVar16 + 0x16) = uVar1;
  *(undefined4 *)(pcVar16 + 0x1a) = uVar7;
  uVar12 = *(undefined4 *)(psVar11->client_random + 0x14);
  uVar1 = *(undefined4 *)(psVar11->client_random + 0x18);
  uVar7 = *(undefined4 *)(psVar11->client_random + 0x1c);
  *(undefined4 *)(pcVar16 + 0x1e) = *(undefined4 *)(psVar11->client_random + 0x10);
  *(undefined4 *)(pcVar16 + 0x22) = uVar12;
  *(undefined4 *)(pcVar16 + 0x26) = uVar1;
  *(undefined4 *)(pcVar16 + 0x2a) = uVar7;
  if (param_1->new_session == 0) {
    pcVar13 = pcVar16 + 0x2f;
    uVar10 = param_1->session->session_id_length;
    pcVar16[0x2e] = (char)uVar10;
    pcVar14 = pcVar13;
    if (uVar10 != 0) {
      if (0x20 < uVar10) {
        iVar2 = 0x346;
        goto LAB_0005a600;
      }
      pcVar14 = pcVar13 + uVar10;
      memcpy(pcVar13,param_1->session->session_id,uVar10);
    }
  }
  else {
    pcVar14 = pcVar16 + 0x2f;
    pcVar16[0x2e] = '\0';
  }
  uVar10 = param_1->d1->cookie_len;
  if (uVar10 < 0x101) {
    *pcVar14 = (char)uVar10;
    pcVar14 = pcVar14 + 1;
    memcpy(pcVar14,param_1->d1->cookie,param_1->d1->cookie_len);
    uVar10 = param_1->d1->cookie_len;
    psVar4 = SSL_get_ciphers(param_1);
    pcVar13 = pcVar14 + uVar10 + 2;
    iVar2 = ssl_cipher_list_to_bytes(param_1,psVar4,pcVar13,0);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0xf8,0xb5,"d1_clnt.c",0x35b);
      return 0xffffffff;
    }
    pcVar14[uVar10] = (char)((uint)iVar2 >> 8);
    pcVar14[uVar10 + 1] = (char)iVar2;
    pcVar14 = pcVar13 + iVar2 + 1;
    if (*(_STACK **)(param_1->psk_server_callback + 0x98) == (_STACK *)0x0) {
      pcVar13[iVar2] = '\x01';
    }
    else {
      iVar5 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
      pcVar13[iVar2] = (char)iVar5 + '\x01';
      if (iVar5 != 0) {
        iVar2 = 0;
        pcVar13 = pcVar14;
        do {
          iVar15 = iVar2 + 1;
          puVar6 = (undefined4 *)sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar2);
          *pcVar13 = (char)*puVar6;
          iVar2 = iVar15;
          pcVar13 = pcVar13 + 1;
        } while (iVar5 != iVar15);
        pcVar14 = pcVar14 + iVar5;
      }
    }
    *pcVar14 = '\0';
    iVar5 = ssl_add_clienthello_tlsext(param_1,pcVar14 + 1,pcVar16 + 0x4000);
    iVar2 = 0x371;
    if (iVar5 != 0) {
      dtls1_set_message_header
                (param_1,pcVar16,1,iVar5 - (int)(pcVar16 + 0xc),0,iVar5 - (int)(pcVar16 + 0xc));
      param_1->init_off = 0;
      param_1->init_num = iVar5 - (int)pcVar16;
      param_1->state = 0x1111;
      dtls1_buffer_message(param_1,0);
      goto LAB_0005a3ee;
    }
  }
  else {
    iVar2 = 0x350;
  }
LAB_0005a600:
  ERR_put_error(0x14,0xf8,0x44,"d1_clnt.c",iVar2);
  return 0xffffffff;
}

