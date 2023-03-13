
undefined4 ssl3_client_hello(SSL *param_1)

{
  char *pcVar1;
  SSL_SESSION *pSVar2;
  ssl3_state_st *psVar3;
  size_t __n;
  int iVar4;
  stack_st_SSL_CIPHER *psVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  
  if (param_1->state != 0x1110) goto LAB_0809a27c;
  pcVar1 = param_1->init_buf->data;
  pSVar2 = param_1->session;
  if ((((((pSVar2 == (SSL_SESSION *)0x0) || (pSVar2->ssl_version != param_1->version)) ||
        ((pSVar2->session_id_length == 0 && (*(int *)(pSVar2->krb5_client_princ + 0x54) == 0)))) ||
       (*(int *)(pSVar2->krb5_client_princ + 4) != 0)) &&
      (iVar4 = ssl_get_new_session(param_1,0), iVar4 == 0)) ||
     (iVar4 = ssl_fill_hello_random(param_1,0,param_1->s3->client_random,0x20), iVar4 < 1))
  goto LAB_0809a2ee;
  pcVar1[4] = (char)((uint)param_1->first_packet >> 8);
  pcVar1[5] = (char)param_1->first_packet;
  psVar3 = param_1->s3;
  *(undefined4 *)(pcVar1 + 6) = *(undefined4 *)psVar3->client_random;
  *(undefined4 *)(pcVar1 + 10) = *(undefined4 *)(psVar3->client_random + 4);
  *(undefined4 *)(pcVar1 + 0xe) = *(undefined4 *)(psVar3->client_random + 8);
  *(undefined4 *)(pcVar1 + 0x12) = *(undefined4 *)(psVar3->client_random + 0xc);
  *(undefined4 *)(pcVar1 + 0x16) = *(undefined4 *)(psVar3->client_random + 0x10);
  *(undefined4 *)(pcVar1 + 0x1a) = *(undefined4 *)(psVar3->client_random + 0x14);
  *(undefined4 *)(pcVar1 + 0x1e) = *(undefined4 *)(psVar3->client_random + 0x18);
  *(undefined4 *)(pcVar1 + 0x22) = *(undefined4 *)(psVar3->client_random + 0x1c);
  if (param_1->new_session == 0) {
    pcVar10 = pcVar1 + 0x27;
    __n = param_1->session->session_id_length;
    pcVar1[0x26] = (char)__n;
    pcVar9 = pcVar10;
    if (__n == 0) goto LAB_0809a160;
    if ((int)__n < 0x21) {
      pcVar9 = pcVar10 + __n;
      memcpy(pcVar10,param_1->session->session_id,__n);
      goto LAB_0809a160;
    }
    iVar4 = 0x2f9;
  }
  else {
    pcVar9 = pcVar1 + 0x27;
    pcVar1[0x26] = '\0';
LAB_0809a160:
    psVar5 = SSL_get_ciphers(param_1);
    iVar4 = ssl_cipher_list_to_bytes(param_1,psVar5,pcVar9 + 2,0);
    if (iVar4 == 0) {
      ERR_put_error(0x14,0x83,0xb5,"s3_clnt.c",0x303);
      goto LAB_0809a2ee;
    }
    pcVar9[1] = (char)iVar4;
    *pcVar9 = (char)((uint)iVar4 >> 8);
    if (((*(byte *)((int)&param_1->references + 2) & 2) == 0) &&
       (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
      iVar6 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
      pcVar10 = pcVar9 + iVar4 + 3;
      pcVar9[iVar4 + 2] = (char)iVar6 + '\x01';
      if (0 < iVar6) {
        iVar4 = 0;
        do {
          puVar7 = (undefined4 *)sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar4);
          pcVar10[iVar4] = (char)*puVar7;
          iVar4 = iVar4 + 1;
        } while (iVar6 != iVar4);
        pcVar10 = pcVar10 + iVar6;
      }
    }
    else {
      pcVar10 = pcVar9 + iVar4 + 3;
      pcVar9[iVar4 + 2] = '\x01';
    }
    *pcVar10 = '\0';
    iVar4 = ssl_prepare_clienthello_tlsext(param_1);
    if (iVar4 < 1) {
      ERR_put_error(0x14,0x83,0xe2,"s3_clnt.c",0x328);
      goto LAB_0809a2ee;
    }
    iVar4 = ssl_add_clienthello_tlsext(param_1,pcVar10 + 1,pcVar1 + 0x4000);
    if (iVar4 != 0) {
      iVar6 = iVar4 - (int)(pcVar1 + 4);
      *pcVar1 = '\x01';
      pcVar1[3] = (char)iVar6;
      pcVar1[1] = (char)((uint)iVar6 >> 0x10);
      pcVar1[2] = (char)((uint)iVar6 >> 8);
      param_1->state = 0x1111;
      param_1->init_num = iVar4 - (int)pcVar1;
      param_1->init_off = 0;
LAB_0809a27c:
      uVar8 = ssl3_do_write(param_1,0x16);
      return uVar8;
    }
    iVar4 = 0x32f;
  }
  ERR_put_error(0x14,0x83,0x44,"s3_clnt.c",iVar4);
LAB_0809a2ee:
  param_1->state = 5;
  return 0xffffffff;
}

