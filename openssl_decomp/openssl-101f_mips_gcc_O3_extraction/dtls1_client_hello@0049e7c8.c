
undefined4 dtls1_client_hello(SSL *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined *puVar19;
  undefined4 uVar20;
  SSL_SESSION *pSVar21;
  int iVar22;
  ssl3_state_st *psVar23;
  uchar *puVar24;
  stack_st_SSL_CIPHER *psVar25;
  int iVar26;
  undefined4 *puVar27;
  undefined4 uVar28;
  uint uVar29;
  uchar *puVar30;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  int iVar31;
  char *pcVar32;
  char *pcVar33;
  char *pcVar34;
  
  if (param_1->state != 0x1110) {
    uVar20 = dtls1_do_write(param_1,0x16);
    return uVar20;
  }
  pSVar21 = param_1->session;
  pcVar32 = param_1->init_buf->data;
  if ((((pSVar21 == (SSL_SESSION *)0x0) || (pSVar21->ssl_version != param_1->version)) ||
      ((pSVar21->session_id_length == 0 && (*(int *)(pSVar21->krb5_client_princ + 0x54) == 0)))) ||
     (*(int *)(pSVar21->krb5_client_princ + 4) != 0)) {
    iVar22 = ssl_get_new_session(param_1,0);
    if (iVar22 == 0) {
      return 0xffffffff;
    }
    psVar23 = param_1->s3;
  }
  else {
    psVar23 = param_1->s3;
  }
  puVar30 = psVar23->client_random;
  if (psVar23->client_random[0] == '\0') {
    puVar24 = psVar23->client_random;
    iVar22 = 0;
    do {
      puVar24 = puVar24 + 1;
      iVar22 = iVar22 + 1;
      if (*puVar24 != '\0') {
        if (iVar22 != 0x20) goto LAB_0049e8b8;
        break;
      }
    } while (iVar22 != 0x20);
    param_4 = 0x20;
    ssl_fill_hello_random(param_1,0);
  }
LAB_0049e8b8:
  pcVar32[0xc] = (char)((uint)param_1->version >> 8);
  pcVar32[0xd] = (char)param_1->version;
  psVar23 = param_1->s3;
  param_1->first_packet = param_1->version;
  uVar29 = (uint)psVar23->client_random & 3;
  uVar1 = (uint)(psVar23->client_random + 4) & 3;
  iVar22 = *(int *)(psVar23->client_random + 4 + -uVar1);
  uVar2 = (uint)(psVar23->client_random + 8) & 3;
  iVar26 = *(int *)(psVar23->client_random + 8 + -uVar2);
  uVar3 = (uint)(psVar23->client_random + 0xc) & 3;
  iVar31 = *(int *)(psVar23->client_random + 0xc + -uVar3);
  uVar4 = (uint)(psVar23->client_random + 0x10) & 3;
  iVar6 = *(int *)(psVar23->client_random + 0x10 + -uVar4);
  uVar5 = (uint)(psVar23->client_random + 0x14) & 3;
  iVar7 = *(int *)(psVar23->client_random + 0x14 + -uVar5);
  uVar8 = (uint)(psVar23->client_random + 3) & 3;
  uVar9 = (uint)(psVar23->client_random + 7) & 3;
  uVar14 = *(uint *)(psVar23->client_random + 7 + -uVar9);
  uVar10 = (uint)(psVar23->client_random + 0xb) & 3;
  uVar15 = *(uint *)(psVar23->client_random + 0xb + -uVar10);
  uVar11 = (uint)(psVar23->client_random + 0xf) & 3;
  uVar16 = *(uint *)(psVar23->client_random + 0xf + -uVar11);
  uVar12 = (uint)(psVar23->client_random + 0x13) & 3;
  uVar17 = *(uint *)(psVar23->client_random + 0x13 + -uVar12);
  uVar13 = (uint)(psVar23->client_random + 0x17) & 3;
  uVar18 = *(uint *)(psVar23->client_random + 0x17 + -uVar13);
  uVar28 = *(undefined4 *)(psVar23->client_random + 0x18);
  uVar20 = *(undefined4 *)(psVar23->client_random + 0x1c);
  *(uint *)(pcVar32 + 0xe) =
       (*(int *)(psVar23->client_random + -uVar29) << uVar29 * 8 |
       in_t3 & 0xffffffffU >> (4 - uVar29) * 8) & -1 << (uVar8 + 1) * 8 |
       *(uint *)(psVar23->client_random + 3 + -uVar8) >> (3 - uVar8) * 8;
  *(uint *)(pcVar32 + 0x12) =
       (iVar22 << uVar1 * 8 | in_t2 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar9 + 1) * 8 |
       uVar14 >> (3 - uVar9) * 8;
  *(uint *)(pcVar32 + 0x16) =
       (iVar26 << uVar2 * 8 | in_t1 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar10 + 1) * 8 |
       uVar15 >> (3 - uVar10) * 8;
  *(uint *)(pcVar32 + 0x1a) =
       (iVar31 << uVar3 * 8 | in_t0 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar11 + 1) * 8 |
       uVar16 >> (3 - uVar11) * 8;
  *(uint *)(pcVar32 + 0x1e) =
       (iVar6 << uVar4 * 8 | param_4 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar12 + 1) * 8 |
       uVar17 >> (3 - uVar12) * 8;
  *(uint *)(pcVar32 + 0x22) =
       (iVar7 << uVar5 * 8 | (uint)puVar30 & 0xffffffffU >> (4 - uVar5) * 8) &
       -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
  *(undefined4 *)(pcVar32 + 0x26) = uVar28;
  *(undefined4 *)(pcVar32 + 0x2a) = uVar20;
  if (param_1->new_session == 0) {
    pcVar33 = pcVar32 + 0x2f;
    uVar29 = param_1->session->session_id_length;
    pcVar32[0x2e] = (char)uVar29;
    pcVar34 = pcVar33;
    if (uVar29 != 0) {
      if (0x20 < uVar29) {
        uVar28 = 0x44;
        uVar20 = 0x346;
        goto LAB_0049ebb0;
      }
      pcVar34 = pcVar33 + uVar29;
      (*(code *)PTR_memcpy_006aabf4)(pcVar33,param_1->session->session_id);
    }
  }
  else {
    pcVar34 = pcVar32 + 0x2f;
    pcVar32[0x2e] = '\0';
  }
  puVar19 = PTR_memcpy_006aabf4;
  uVar29 = param_1->d1->cookie_len;
  if (uVar29 < 0x101) {
    *pcVar34 = (char)uVar29;
    (*(code *)puVar19)(pcVar34 + 1,param_1->d1->cookie,param_1->d1->cookie_len);
    uVar29 = param_1->d1->cookie_len;
    psVar25 = SSL_get_ciphers(param_1);
    pcVar34 = pcVar34 + 1 + uVar29;
    iVar22 = ssl_cipher_list_to_bytes(param_1,psVar25,pcVar34 + 2,0);
    if (iVar22 == 0) {
      uVar28 = 0xb5;
      uVar20 = 0x35b;
    }
    else {
      pcVar34[1] = (char)iVar22;
      *pcVar34 = (char)((uint)iVar22 >> 8);
      if (*(int *)(param_1->psk_server_callback + 0x98) == 0) {
        pcVar34[iVar22 + 2] = '\x01';
        pcVar33 = pcVar34 + iVar22 + 3;
      }
      else {
        pcVar33 = pcVar34 + iVar22 + 3;
        iVar26 = (*(code *)PTR_sk_num_006a7f2c)();
        pcVar34[iVar22 + 2] = (char)iVar26 + '\x01';
        if (iVar26 != 0) {
          iVar22 = 0;
          pcVar34 = pcVar33;
          do {
            iVar31 = iVar22 + 1;
            puVar27 = (undefined4 *)
                      (*(code *)PTR_sk_value_006a7f24)
                                (*(undefined4 *)(param_1->psk_server_callback + 0x98),iVar22);
            *pcVar34 = (char)*puVar27;
            iVar22 = iVar31;
            pcVar34 = pcVar34 + 1;
          } while (iVar26 != iVar31);
          pcVar33 = pcVar33 + iVar26;
        }
      }
      *pcVar33 = '\0';
      iVar22 = ssl_add_clienthello_tlsext(param_1,pcVar33 + 1,pcVar32 + 0x4000);
      if (iVar22 != 0) {
        dtls1_set_message_header
                  (param_1,pcVar32,1,iVar22 - (int)(pcVar32 + 0xc),0,iVar22 - (int)(pcVar32 + 0xc));
        param_1->init_off = 0;
        param_1->init_num = iVar22 - (int)pcVar32;
        param_1->state = 0x1111;
        dtls1_buffer_message(param_1,0);
        uVar20 = dtls1_do_write(param_1,0x16);
        return uVar20;
      }
      uVar28 = 0x44;
      uVar20 = 0x371;
    }
  }
  else {
    uVar28 = 0x44;
    uVar20 = 0x350;
  }
LAB_0049ebb0:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf8,uVar28,"d1_clnt.c",uVar20);
  return 0xffffffff;
}

