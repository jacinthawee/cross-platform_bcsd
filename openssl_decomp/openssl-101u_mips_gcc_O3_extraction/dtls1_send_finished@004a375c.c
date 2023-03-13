
int dtls1_send_finished(int param_1,int param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  undefined uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  BIO *pBVar13;
  short sVar14;
  SSL *ssl;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  undefined *unaff_s2;
  undefined4 unaff_s3;
  char *unaff_s4;
  int iVar20;
  int unaff_s5;
  undefined *puStack_100;
  undefined *apuStack_fc [21];
  undefined4 uStack_a8;
  SSL *pSStack_74;
  int iStack_70;
  undefined *puStack_6c;
  undefined *puStack_68;
  undefined4 uStack_64;
  char *pcStack_60;
  int iStack_5c;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  puStack_6c = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_64 = unaff_s3;
  if (*(int *)(param_1 + 0x34) == param_2) {
    iVar8 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    iVar6 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x14))
                      (param_1,param_4,param_5,*(int *)(param_1 + 0x58) + 0x234);
    puVar5 = PTR_memcpy_006a9aec;
    iVar15 = *(int *)(param_1 + 0x58);
    *(int *)(iVar15 + 0x2b4) = iVar6;
    (*(code *)puVar5)(iVar8 + 0xc,iVar15 + 0x234,iVar6);
    if (*(int *)(param_1 + 4) == 0x1000) {
      if (0x40 < iVar6) {
        OpenSSLDie("d1_both.c",0x416,"i <= EVP_MAX_MD_SIZE");
      }
      (*(code *)PTR_memcpy_006a9aec)
                (*(int *)(param_1 + 0x58) + 0x394,*(int *)(param_1 + 0x58) + 0x234,iVar6);
      *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)iVar6;
    }
    else {
      if (0x40 < iVar6) {
        OpenSSLDie("d1_both.c",0x41a,"i <= EVP_MAX_MD_SIZE");
      }
      (*(code *)PTR_memcpy_006a9aec)
                (*(int *)(param_1 + 0x58) + 0x3d5,*(int *)(param_1 + 0x58) + 0x234,iVar6);
      *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)iVar6;
    }
    unaff_s4 = "-check_ss_sig";
    iVar15 = *(int *)(param_1 + 0x5c);
    if (*(int *)(iVar15 + 0x254) == 0) {
      sVar14 = *(short *)(iVar15 + 0x226);
      *(short *)(iVar15 + 0x224) = sVar14;
      *(short *)(iVar15 + 0x226) = sVar14 + 1;
    }
    else {
      sVar14 = *(short *)(iVar15 + 0x224);
    }
    unaff_s5 = iVar6 + 0xc;
    *(short *)(iVar15 + 0x268) = sVar14;
    *(int *)(iVar15 + 0x264) = iVar6;
    *(int *)(iVar15 + 0x270) = iVar6;
    *(undefined *)(iVar15 + 0x260) = 0x14;
    *(undefined4 *)(iVar15 + 0x26c) = 0;
    *(int *)(param_1 + 0x44) = unaff_s5;
    *(undefined4 *)(param_1 + 0x48) = 0;
    unaff_s2 = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
    uStack_64 = param_3;
    if (unaff_s2 == (undefined *)0x0) {
LAB_004a39c8:
      *(undefined4 *)(param_1 + 0x34) = param_3;
    }
    else {
      pvVar7 = (void *)0x0;
      if ((unaff_s5 == 0) ||
         (pvVar7 = CRYPTO_malloc(unaff_s5,"d1_both.c",0xba), pvVar7 != (void *)0x0)) {
        puVar5 = PTR_memcpy_006a9aec;
        iVar6 = *(int *)(param_1 + 0x3c);
        uVar10 = *(undefined4 *)(param_1 + 0x44);
        *(void **)(unaff_s2 + 0x2c) = pvVar7;
        *(undefined4 *)(unaff_s2 + 0x30) = 0;
        (*(code *)puVar5)(pvVar7,*(undefined4 *)(iVar6 + 4),uVar10);
        iVar6 = *(int *)(param_1 + 0x5c);
        iVar15 = *(int *)(iVar6 + 0x264);
        if (iVar15 + 0xc != *(int *)(param_1 + 0x44)) {
          OpenSSLDie("d1_both.c",0x510,
                     "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num"
                    );
          iVar6 = *(int *)(param_1 + 0x5c);
          iVar15 = *(int *)(iVar6 + 0x264);
        }
        uVar2 = *(ushort *)(iVar6 + 0x268);
        *(int *)(unaff_s2 + 4) = iVar15;
        puVar5 = PTR_pitem_new_006a829c;
        *(ushort *)(unaff_s2 + 8) = uVar2;
        uVar1 = *(undefined *)(iVar6 + 0x260);
        *(undefined4 *)(unaff_s2 + 0xc) = 0;
        *unaff_s2 = uVar1;
        uVar18 = *(undefined4 *)(param_1 + 0x8c);
        uVar17 = *(undefined4 *)(param_1 + 0x90);
        uVar16 = *(undefined4 *)(param_1 + 0x94);
        uVar10 = *(undefined4 *)(param_1 + 0xc0);
        uVar3 = *(undefined2 *)(*(int *)(param_1 + 0x5c) + 0x20a);
        *(undefined4 *)(unaff_s2 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x264);
        *(undefined4 *)(unaff_s2 + 0x14) = 0;
        *(undefined4 *)(unaff_s2 + 0x18) = uVar18;
        *(undefined4 *)(unaff_s2 + 0x1c) = uVar17;
        *(undefined4 *)(unaff_s2 + 0x20) = uVar16;
        *(undefined4 *)(unaff_s2 + 0x24) = uVar10;
        *(undefined2 *)(unaff_s2 + 0x28) = uVar3;
        local_2c = 0;
        local_28 = (uVar2 & 0x7fff) << 1;
        iVar6 = (*(code *)puVar5)(&local_2c,unaff_s2);
        if (iVar6 != 0) {
          (*(code *)PTR_pqueue_insert_006a82a0)
                    (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x248),iVar6);
          goto LAB_004a39c8;
        }
        if (*(int *)(unaff_s2 + 0x14) != 0) {
          (*(code *)PTR_EVP_CIPHER_CTX_free_006a82dc)(*(undefined4 *)(unaff_s2 + 0x18));
          (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(*(undefined4 *)(unaff_s2 + 0x1c));
        }
        if (*(void **)(unaff_s2 + 0x2c) != (void *)0x0) {
          CRYPTO_free(*(void **)(unaff_s2 + 0x2c));
        }
        if (*(void **)(unaff_s2 + 0x30) != (void *)0x0) {
          CRYPTO_free(*(void **)(unaff_s2 + 0x30));
        }
      }
      CRYPTO_free(unaff_s2);
      *(undefined4 *)(param_1 + 0x34) = param_3;
    }
  }
  iVar15 = 0x16;
  iVar6 = dtls1_do_write(param_1);
  if (local_24 == *(int *)puStack_6c) {
    return iVar6;
  }
  iVar6 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  iVar20 = *(int *)(iVar6 + 0x3c);
  pSStack_74 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  iStack_70 = param_1;
  puStack_68 = unaff_s2;
  pcStack_60 = unaff_s4;
  iStack_5c = unaff_s5;
  iVar8 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar20,10);
  if (iVar8 == 0) {
    iVar6 = 0xff;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xff,7,"d1_both.c",0x479);
    iVar15 = 0;
  }
  else {
    if (iVar15 == 0) {
      iVar15 = 0xf;
    }
    else {
      iVar15 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)
                         (apuStack_fc,*(undefined4 *)(*(int *)(iVar6 + 0xe4) + 0xc),iVar15,0);
      if (iVar15 == 0) {
        iVar6 = 0xff;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xff,0xb,"d1_both.c",0x480);
LAB_004a3cb4:
        iVar15 = 0;
        goto LAB_004a3cb8;
      }
      (*(code *)PTR_X509_verify_cert_006a728c)(apuStack_fc);
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      iVar15 = 0xf;
      for (iVar8 = 0; iVar9 = (*(code *)PTR_sk_num_006a6e2c)(uStack_a8), iVar8 < iVar9;
          iVar8 = iVar8 + 1) {
        uVar10 = (*(code *)PTR_sk_value_006a6e24)(uStack_a8,iVar8);
        iVar9 = (*(code *)PTR_i2d_X509_006a76e8)(uVar10,0);
        iVar19 = iVar9 + 3 + iVar15;
        iVar11 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar20,iVar19);
        puVar4 = PTR_i2d_X509_006a76e8;
        if (iVar11 == 0) {
          iVar6 = 0x127;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x127,7,"d1_both.c",0x464);
          (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(apuStack_fc);
          goto LAB_004a3cb4;
        }
        puStack_100 = (undefined *)(*(int *)(iVar20 + 4) + iVar15);
        *puStack_100 = (char)((uint)iVar9 >> 0x10);
        puStack_100[1] = (char)((uint)iVar9 >> 8);
        puStack_100[2] = (char)iVar9;
        puStack_100 = puStack_100 + 3;
        (*(code *)puVar4)(uVar10,&puStack_100);
        iVar15 = iVar19;
      }
      (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(apuStack_fc);
    }
    for (iVar8 = 0;
        iVar9 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(iVar6 + 0xe4) + 0x94)),
        iVar8 < iVar9; iVar8 = iVar8 + 1) {
      uVar10 = (*(code *)PTR_sk_value_006a6e24)
                         (*(undefined4 *)(*(int *)(iVar6 + 0xe4) + 0x94),iVar8);
      iVar9 = (*(code *)PTR_i2d_X509_006a76e8)(uVar10,0);
      iVar19 = iVar9 + 3 + iVar15;
      iVar11 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar20,iVar19);
      puVar4 = PTR_i2d_X509_006a76e8;
      if (iVar11 == 0) {
        iVar6 = 0x127;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x127,7,"d1_both.c",0x464);
        goto LAB_004a3cb4;
      }
      apuStack_fc[0] = (undefined *)(*(int *)(iVar20 + 4) + iVar15);
      *apuStack_fc[0] = (char)((uint)iVar9 >> 0x10);
      apuStack_fc[0][1] = (char)((uint)iVar9 >> 8);
      apuStack_fc[0][2] = (char)iVar9;
      apuStack_fc[0] = apuStack_fc[0] + 3;
      (*(code *)puVar4)(uVar10,apuStack_fc);
      iVar15 = iVar19;
    }
    iVar8 = iVar15 + -0xf;
    iVar20 = *(int *)(iVar20 + 4);
    *(char *)(iVar20 + 0xe) = (char)iVar8;
    *(char *)(iVar20 + 0xc) = (char)((uint)iVar8 >> 0x10);
    *(char *)(iVar20 + 0xd) = (char)((uint)iVar8 >> 8);
    iVar8 = *(int *)(iVar6 + 0x5c);
    if (*(int *)(iVar8 + 0x254) == 0) {
      sVar14 = *(short *)(iVar8 + 0x226);
      *(short *)(iVar8 + 0x224) = sVar14;
      *(short *)(iVar8 + 0x226) = sVar14 + 1;
    }
    else {
      sVar14 = *(short *)(iVar8 + 0x224);
    }
    iVar6 = 0xb;
    *(short *)(iVar8 + 0x268) = sVar14;
    *(int *)(iVar8 + 0x264) = iVar15 + -0xc;
    *(undefined4 *)(iVar8 + 0x26c) = 0;
    *(undefined *)(iVar8 + 0x260) = 0xb;
    *(int *)(iVar8 + 0x270) = iVar15 + -0xc;
  }
LAB_004a3cb8:
  if (pSStack_74 == *(SSL **)puVar5) {
    return iVar15;
  }
  ssl = pSStack_74;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar6 < 1) {
    iVar15 = dtls1_is_timer_expired();
    if (iVar15 == 0) {
      return iVar6;
    }
    uVar12 = SSL_state(ssl);
    if (((uVar12 & 0x3000) != 0) || (ssl->tlsext_heartbeat != 0)) {
      iVar6 = dtls1_handle_timeout(ssl);
      return iVar6;
    }
    pBVar13 = SSL_get_rbio(ssl);
    (*(code *)PTR_BIO_set_flags_006a7570)(pBVar13,1);
  }
  else {
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid state reached %s:%d","d1_both.c",0x4a7)
    ;
    iVar6 = 1;
  }
  return iVar6;
}

