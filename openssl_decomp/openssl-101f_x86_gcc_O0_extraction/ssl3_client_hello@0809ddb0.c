
undefined4 ssl3_client_hello(SSL *param_1)

{
  char *pcVar1;
  SSL_SESSION *pSVar2;
  ssl3_state_st *psVar3;
  size_t __n;
  undefined4 uVar4;
  int iVar5;
  stack_st_SSL_CIPHER *psVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  
  if (param_1->state != 0x1110) goto LAB_0809ddc4;
  pcVar1 = param_1->init_buf->data;
  pSVar2 = param_1->session;
  if (((((pSVar2 == (SSL_SESSION *)0x0) || (pSVar2->ssl_version != param_1->version)) ||
       ((pSVar2->session_id_length == 0 && (*(int *)(pSVar2->krb5_client_princ + 0x54) == 0)))) ||
      (*(int *)(pSVar2->krb5_client_princ + 4) != 0)) &&
     (iVar5 = ssl_get_new_session(param_1,0), iVar5 == 0)) {
    return 0xffffffff;
  }
  iVar5 = ssl_fill_hello_random(param_1,0,param_1->s3->client_random,0x20);
  if (iVar5 < 1) {
    return 0xffffffff;
  }
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
    if (__n == 0) goto LAB_0809dec8;
    if ((int)__n < 0x21) {
      pcVar9 = pcVar10 + __n;
      memcpy(pcVar10,param_1->session->session_id,__n);
      goto LAB_0809dec8;
    }
    iVar7 = 0x2e6;
  }
  else {
    pcVar9 = pcVar1 + 0x27;
    pcVar1[0x26] = '\0';
LAB_0809dec8:
    psVar6 = SSL_get_ciphers(param_1);
    iVar5 = ssl_cipher_list_to_bytes(param_1,psVar6,pcVar9 + 2,0);
    if (iVar5 == 0) {
      iVar7 = 0x2f1;
      iVar5 = 0xb5;
      goto LAB_0809e037;
    }
    pcVar9[1] = (char)iVar5;
    *pcVar9 = (char)((uint)iVar5 >> 8);
    if (((*(byte *)((int)&param_1->references + 2) & 2) == 0) &&
       (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
      iVar7 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
      pcVar10 = pcVar9 + iVar5 + 3;
      pcVar9[iVar5 + 2] = (char)iVar7 + '\x01';
      if (0 < iVar7) {
        iVar5 = 0;
        do {
          puVar8 = (undefined4 *)sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar5);
          pcVar10[iVar5] = (char)*puVar8;
          iVar5 = iVar5 + 1;
        } while (iVar7 != iVar5);
        pcVar10 = pcVar10 + iVar7;
      }
    }
    else {
      pcVar10 = pcVar9 + iVar5 + 3;
      pcVar9[iVar5 + 2] = '\x01';
    }
    *pcVar10 = '\0';
    iVar5 = ssl_prepare_clienthello_tlsext(param_1);
    if (iVar5 < 1) {
      iVar7 = 0x317;
      iVar5 = 0xe2;
      goto LAB_0809e037;
    }
    iVar5 = ssl_add_clienthello_tlsext(param_1,pcVar10 + 1,pcVar1 + 0x4000);
    if (iVar5 != 0) {
      iVar7 = iVar5 - (int)(pcVar1 + 4);
      *pcVar1 = '\x01';
      pcVar1[3] = (char)iVar7;
      pcVar1[1] = (char)((uint)iVar7 >> 0x10);
      pcVar1[2] = (char)((uint)iVar7 >> 8);
      param_1->state = 0x1111;
      param_1->init_num = iVar5 - (int)pcVar1;
      param_1->init_off = 0;
LAB_0809ddc4:
      uVar4 = ssl3_do_write(param_1,0x16);
      return uVar4;
    }
    iVar7 = 0x31c;
  }
  iVar5 = 0x44;
LAB_0809e037:
  ERR_put_error(0x14,0x83,iVar5,"s3_clnt.c",iVar7);
  return 0xffffffff;
}

