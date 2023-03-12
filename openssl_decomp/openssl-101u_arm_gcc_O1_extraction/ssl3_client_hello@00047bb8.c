
undefined4 ssl3_client_hello(SSL *param_1)

{
  int iVar1;
  undefined4 uVar2;
  stack_st_SSL_CIPHER *psVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  SSL_SESSION *pSVar7;
  ssl3_state_st *psVar8;
  size_t __n;
  undefined4 uVar9;
  char *pcVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  int iVar15;
  
  pcVar14 = param_1->init_buf->data;
  if (param_1->state != 0x1110) goto LAB_00047d40;
  pSVar7 = param_1->session;
  if ((((((pSVar7 == (SSL_SESSION *)0x0) || (pSVar7->ssl_version != param_1->version)) ||
        ((pSVar7->session_id_length == 0 && (*(int *)(pSVar7->krb5_client_princ + 0x54) == 0)))) ||
       (*(int *)(pSVar7->krb5_client_princ + 4) != 0)) &&
      (iVar1 = ssl_get_new_session(param_1,0), iVar1 == 0)) ||
     (iVar1 = ssl_fill_hello_random(param_1,0,param_1->s3->client_random,0x20), iVar1 < 1))
  goto LAB_00047d8c;
  pcVar14[4] = (char)((uint)param_1->first_packet >> 8);
  pcVar14[5] = (char)param_1->first_packet;
  psVar8 = param_1->s3;
  uVar9 = *(undefined4 *)(psVar8->client_random + 4);
  uVar2 = *(undefined4 *)(psVar8->client_random + 8);
  uVar6 = *(undefined4 *)(psVar8->client_random + 0xc);
  *(undefined4 *)(pcVar14 + 6) = *(undefined4 *)psVar8->client_random;
  *(undefined4 *)(pcVar14 + 10) = uVar9;
  *(undefined4 *)(pcVar14 + 0xe) = uVar2;
  *(undefined4 *)(pcVar14 + 0x12) = uVar6;
  uVar9 = *(undefined4 *)(psVar8->client_random + 0x14);
  uVar2 = *(undefined4 *)(psVar8->client_random + 0x18);
  uVar6 = *(undefined4 *)(psVar8->client_random + 0x1c);
  *(undefined4 *)(pcVar14 + 0x16) = *(undefined4 *)(psVar8->client_random + 0x10);
  *(undefined4 *)(pcVar14 + 0x1a) = uVar9;
  *(undefined4 *)(pcVar14 + 0x1e) = uVar2;
  *(undefined4 *)(pcVar14 + 0x22) = uVar6;
  if (param_1->new_session == 0) {
    pcVar10 = pcVar14 + 0x27;
    __n = param_1->session->session_id_length;
    pcVar14[0x26] = (char)__n;
    pcVar11 = pcVar10;
    if (__n == 0) goto LAB_00047c7e;
    if ((int)__n < 0x21) {
      pcVar11 = pcVar10 + __n;
      memcpy(pcVar10,param_1->session->session_id,__n);
      goto LAB_00047c7e;
    }
    iVar1 = 0x2f9;
  }
  else {
    pcVar11 = pcVar14 + 0x27;
    pcVar14[0x26] = '\0';
LAB_00047c7e:
    pcVar10 = pcVar11 + 2;
    psVar3 = SSL_get_ciphers(param_1);
    iVar1 = ssl_cipher_list_to_bytes(param_1,psVar3,pcVar10,0);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x83,0xb5,"s3_clnt.c",0x303);
      goto LAB_00047d8c;
    }
    pcVar11[1] = (char)iVar1;
    *pcVar11 = (char)((uint)iVar1 >> 8);
    pcVar11 = pcVar10 + iVar1 + 1;
    uVar12 = param_1->references & 0x20000;
    if ((uVar12 == 0) && (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
      uVar4 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
      pcVar10[iVar1] = (char)uVar4 + '\x01';
      pcVar10 = pcVar11;
      if (0 < (int)uVar4) {
        do {
          uVar13 = uVar12 + 1;
          puVar5 = (undefined4 *)sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),uVar12);
          *pcVar10 = (char)*puVar5;
          uVar12 = uVar13;
          pcVar10 = pcVar10 + 1;
        } while (uVar13 != uVar4);
        pcVar11 = pcVar11 + uVar13;
      }
    }
    else {
      pcVar10[iVar1] = '\x01';
    }
    *pcVar11 = '\0';
    iVar1 = ssl_prepare_clienthello_tlsext(param_1);
    if (iVar1 < 1) {
      ERR_put_error(0x14,0x83,0xe2,"s3_clnt.c",0x328);
      goto LAB_00047d8c;
    }
    iVar1 = ssl_add_clienthello_tlsext(param_1,pcVar11 + 1,pcVar14 + 0x4000);
    if (iVar1 != 0) {
      iVar15 = iVar1 - (int)(pcVar14 + 4);
      pcVar14[3] = (char)iVar15;
      *pcVar14 = '\x01';
      pcVar14[1] = (char)((uint)iVar15 >> 0x10);
      pcVar14[2] = (char)((uint)iVar15 >> 8);
      param_1->init_num = iVar1 - (int)pcVar14;
      param_1->init_off = 0;
      param_1->state = 0x1111;
LAB_00047d40:
      uVar2 = ssl3_do_write(param_1,0x16);
      return uVar2;
    }
    iVar1 = 0x32f;
  }
  ERR_put_error(0x14,0x83,0x44,"s3_clnt.c",iVar1);
LAB_00047d8c:
  param_1->state = 5;
  return 0xffffffff;
}

