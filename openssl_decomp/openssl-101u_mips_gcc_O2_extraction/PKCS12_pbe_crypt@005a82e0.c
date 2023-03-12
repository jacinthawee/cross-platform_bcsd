
uchar * PKCS12_pbe_crypt(X509_ALGOR *algor,char *pass,int passlen,uchar *in,int inlen,uchar **data,
                        int *datalen,int en_de)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  X509_ALGOR *pXVar4;
  uchar *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  PKCS12 *a;
  ASN1_OBJECT *pAVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 ****ppppuVar13;
  undefined4 ****ppppuVar14;
  undefined4 uVar15;
  char *pcVar16;
  PKCS7 *pPVar17;
  undefined4 ***pppuVar18;
  char *unaff_s4;
  code *pcVar19;
  int iStack_288;
  int iStack_284;
  undefined auStack_280 [140];
  int iStack_1f4;
  uchar *puStack_1ec;
  undefined4 ****ppppuStack_1e8;
  undefined4 ****ppppuStack_1e4;
  undefined *puStack_1e0;
  undefined4 ****ppppuStack_1dc;
  char *pcStack_1d8;
  uchar *puStack_1d4;
  int iStack_1d0;
  code *pcStack_1cc;
  uchar *puStack_1b8;
  int iStack_1b4;
  undefined *puStack_1b0;
  undefined4 ****ppppuStack_1a4;
  uchar auStack_1a0 [140];
  undefined4 *puStack_114;
  X509_ALGOR *pXStack_10c;
  undefined *puStack_108;
  undefined *puStack_104;
  undefined4 ***pppuStack_100;
  char *pcStack_fc;
  uchar *puStack_f8;
  uchar **ppuStack_f4;
  int *piStack_f0;
  code *pcStack_ec;
  int *local_d8;
  int local_d4;
  undefined *local_d0;
  int local_c8;
  char *local_c4;
  undefined4 ***local_bc;
  undefined auStack_b8 [140];
  undefined4 ****local_2c;
  
  puStack_104 = PTR___stack_chk_guard_006a9ae8;
  puStack_108 = auStack_b8;
  local_d0 = &_gp;
  local_2c = *(undefined4 *****)PTR___stack_chk_guard_006a9ae8;
  local_c8 = passlen;
  local_c4 = pass;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(puStack_108);
  local_d4 = en_de;
  local_d8 = (int *)puStack_108;
  iVar3 = (**(code **)(local_d0 + -0x5bb8))(algor->algorithm,local_c4,local_c8,algor->parameter);
  if (iVar3 == 0) {
    ppppuStack_1dc = (undefined4 ****)&DAT_00000073;
    pcVar16 = "p12_decr.c";
    local_d8 = (int *)0x57;
    puStack_1d4 = &DAT_00000077;
    (**(code **)(local_d0 + -0x6eac))(0x23,0x77,0x73,"p12_decr.c");
    pXVar4 = (X509_ALGOR *)0x0;
  }
  else {
    unaff_s4 = "encrypt";
    iVar3 = (**(code **)(local_d0 + -0x5bb4))(puStack_108);
    pXVar4 = (X509_ALGOR *)(**(code **)(local_d0 + -0x7dd8))(iVar3 + inlen,"p12_decr.c",0x5b);
    if (pXVar4 == (X509_ALGOR *)0x0) {
      pcVar16 = "p12_decr.c";
      ppppuStack_1dc = (undefined4 ****)&DAT_00000041;
      puStack_1d4 = &DAT_00000077;
      local_d8 = (int *)&DAT_0000005c;
      (**(code **)(local_d0 + -0x6eac))(0x23,0x77,0x41,"p12_decr.c");
LAB_005a8418:
      pcVar19 = *(code **)(local_d0 + -0x736c);
    }
    else {
      ppppuStack_1dc = &local_bc;
      local_d8 = (int *)inlen;
      pcVar16 = (char *)in;
      iVar3 = (**(code **)(local_d0 + -0x62dc))(puStack_108,pXVar4,ppppuStack_1dc,in);
      pppuVar18 = local_bc;
      if (iVar3 == 0) {
        (**(code **)(local_d0 + -0x7f58))(pXVar4);
        ppppuStack_1dc = (undefined4 ****)&DAT_00000006;
        local_d8 = (int *)&DAT_00000063;
        pcVar19 = *(code **)(local_d0 + -0x6eac);
        pppuVar18 = (undefined4 ***)inlen;
LAB_005a8404:
        pcVar16 = "p12_decr.c";
        puStack_1d4 = &DAT_00000077;
        pXVar4 = (X509_ALGOR *)0x0;
        (*pcVar19)(0x23,0x77,ppppuStack_1dc,"p12_decr.c");
        inlen = (int)pppuVar18;
        goto LAB_005a8418;
      }
      puStack_1d4 = (uchar *)((int)&pXVar4->algorithm + (int)local_bc);
      iVar3 = (**(code **)(local_d0 + -0x62d8))(puStack_108);
      if (iVar3 == 0) {
        (**(code **)(local_d0 + -0x7f58))(pXVar4);
        ppppuStack_1dc = (undefined4 ****)&DAT_00000074;
        local_d8 = (int *)&DAT_0000006c;
        pcVar19 = *(code **)(local_d0 + -0x6eac);
        goto LAB_005a8404;
      }
      inlen = (int)pppuVar18 + (int)local_bc;
      if (datalen != (int *)0x0) {
        *datalen = inlen;
      }
      pcVar19 = *(code **)(local_d0 + -0x736c);
      if (data != (uchar **)0x0) {
        *data = (uchar *)pXVar4;
      }
    }
    (*pcVar19)(puStack_108);
    algor = pXVar4;
  }
  if (local_2c == *(undefined4 *****)puStack_104) {
    return (uchar *)pXVar4;
  }
  pcStack_ec = PKCS12_item_decrypt_d2i;
  ppppuStack_1e8 = local_2c;
  (**(code **)(local_d0 + -0x5330))();
  puStack_1e0 = PTR___stack_chk_guard_006a9ae8;
  piStack_f0 = datalen;
  ppuStack_f4 = data;
  puStack_1b0 = &_gp;
  puStack_114 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  ppppuStack_1e4 = (undefined4 ****)local_d8[2];
  iStack_1d0 = *local_d8;
  pXStack_10c = algor;
  pppuStack_100 = (undefined4 ***)inlen;
  pcStack_fc = unaff_s4;
  puStack_f8 = in;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_1a0);
  iStack_1b4 = 0;
  puStack_1b8 = auStack_1a0;
  iVar3 = (**(code **)(puStack_1b0 + -0x5bb8))
                    (*ppppuStack_1e8,ppppuStack_1dc,pcVar16,ppppuStack_1e8[1]);
  if (iVar3 == 0) {
    puStack_1b8 = (uchar *)0x57;
    (**(code **)(puStack_1b0 + -0x6eac))(0x23,0x77,0x73,"p12_decr.c");
LAB_005a8670:
    pcVar16 = "p12_decr.c";
    ppppuVar14 = (undefined4 ****)0x75;
    ppppuVar13 = (undefined4 ****)&DAT_0000006a;
    puStack_1b8 = (uchar *)0x8b;
    (**(code **)(puStack_1b0 + -0x6eac))(0x23,0x6a,0x75,"p12_decr.c");
    puVar5 = (uchar *)0x0;
    puStack_1ec = auStack_1a0;
  }
  else {
    iVar3 = (**(code **)(puStack_1b0 + -0x5bb4))(auStack_1a0);
    ppppuStack_1e8 =
         (undefined4 ****)(**(code **)(puStack_1b0 + -0x7dd8))(iStack_1d0 + iVar3,"p12_decr.c",0x5b)
    ;
    if (ppppuStack_1e8 == (undefined4 ****)0x0) {
      puStack_1b8 = (uchar *)0x5c;
      (**(code **)(puStack_1b0 + -0x6eac))(0x23,0x77,0x41,"p12_decr.c");
LAB_005a8660:
      (**(code **)(puStack_1b0 + -0x736c))(auStack_1a0);
      goto LAB_005a8670;
    }
    ppppuStack_1dc = &ppppuStack_1a4;
    puStack_1b8 = (uchar *)iStack_1d0;
    iVar3 = (**(code **)(puStack_1b0 + -0x62dc))
                      (auStack_1a0,ppppuStack_1e8,ppppuStack_1dc,ppppuStack_1e4);
    ppppuVar13 = ppppuStack_1a4;
    if (iVar3 == 0) {
      (**(code **)(puStack_1b0 + -0x7f58))(ppppuStack_1e8);
      puStack_1b8 = (uchar *)0x63;
      (**(code **)(puStack_1b0 + -0x6eac))(0x23,0x77,6,"p12_decr.c");
      goto LAB_005a8660;
    }
    iVar3 = (**(code **)(puStack_1b0 + -0x62d8))
                      (auStack_1a0,(undefined *)((int)ppppuStack_1e8 + (int)ppppuStack_1a4),
                       ppppuStack_1dc);
    if (iVar3 == 0) {
      (**(code **)(puStack_1b0 + -0x7f58))(ppppuStack_1e8);
      puStack_1b8 = (uchar *)0x6c;
      (**(code **)(puStack_1b0 + -0x6eac))(0x23,0x77,0x74,"p12_decr.c");
      ppppuStack_1e4 = ppppuVar13;
      goto LAB_005a8660;
    }
    ppppuStack_1e4 = (undefined4 ****)((int)ppppuVar13 + (int)ppppuStack_1a4);
    (**(code **)(puStack_1b0 + -0x736c))(auStack_1a0);
    ppppuVar13 = ppppuStack_1dc;
    ppppuVar14 = ppppuStack_1e4;
    pcVar16 = (char *)puStack_1d4;
    ppppuStack_1a4 = ppppuStack_1e8;
    puVar5 = (uchar *)(**(code **)(puStack_1b0 + -0x676c))
                                (0,ppppuStack_1dc,ppppuStack_1e4,puStack_1d4);
    if (local_d4 != 0) {
      ppppuVar13 = ppppuStack_1e4;
      (**(code **)(puStack_1b0 + -0x7d6c))(ppppuStack_1e8,ppppuStack_1e4);
    }
    if (puVar5 == (uchar *)0x0) {
      pcVar16 = "p12_decr.c";
      ppppuVar14 = (undefined4 ****)&DAT_00000065;
      ppppuVar13 = (undefined4 ****)&DAT_0000006a;
      puStack_1b8 = (uchar *)0x9f;
      (**(code **)(puStack_1b0 + -0x6eac))(0x23,0x6a,0x65,"p12_decr.c");
    }
    (**(code **)(puStack_1b0 + -0x7f58))(ppppuStack_1e8);
    puStack_1ec = puVar5;
  }
  if (puStack_114 == *(undefined4 **)puStack_1e0) {
    return puVar5;
  }
  pcStack_1cc = PKCS12_item_i2d_encrypt;
  puVar12 = puStack_114;
  (**(code **)(puStack_1b0 + -0x5330))();
  iVar3 = (int)puStack_1b8;
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pcStack_1d8 = "encrypt";
  iStack_288 = 0;
  iStack_1f4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar6 = (int *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
  if (piVar6 == (int *)0x0) {
    uVar15 = 0x41;
    uVar11 = 0xb2;
  }
  else {
    iVar7 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar3,&iStack_288,ppppuVar13);
    iVar3 = iStack_288;
    if (iStack_288 != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_280);
      iVar8 = (*(code *)PTR_EVP_PBE_CipherInit_006a9228)
                        (*puVar12,ppppuVar14,pcVar16,puVar12[1],auStack_280,1);
      if (iVar8 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x77,0x73,"p12_decr.c",0x57);
      }
      else {
        iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(auStack_280);
        iVar8 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar7 + iVar8,"p12_decr.c",0x5b);
        if (iVar8 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x77,0x41,"p12_decr.c",0x5c);
        }
        else {
          iVar9 = (*(code *)PTR_EVP_CipherUpdate_006a8b04)
                            (auStack_280,iVar8,&iStack_284,iVar3,iVar7);
          iVar3 = iStack_284;
          if (iVar9 == 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
            (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x77,6,"p12_decr.c",99);
          }
          else {
            iVar9 = (*(code *)PTR_EVP_CipherFinal_ex_006a8b08)
                              (auStack_280,iVar8 + iStack_284,&iStack_284);
            puVar1 = PTR_EVP_CIPHER_CTX_cleanup_006a7a74;
            if (iVar9 != 0) {
              piVar6[2] = iVar8;
              *piVar6 = iStack_284 + iVar3;
              (*(code *)puVar1)(auStack_280);
              if (iStack_1b4 != 0) {
                (*(code *)PTR_OPENSSL_cleanse_006a7074)(iStack_288,iVar7);
              }
              (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_288);
              goto LAB_005a89b8;
            }
            (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
            (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x77,0x74,"p12_decr.c",0x6c);
          }
        }
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_280);
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6c,0x67,"p12_decr.c",0xbc);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_288);
      piVar6 = (int *)0x0;
      goto LAB_005a89b8;
    }
    uVar15 = 0x66;
    uVar11 = 0xb7;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6c,uVar15,"p12_decr.c",uVar11);
  piVar6 = (int *)0x0;
LAB_005a89b8:
  if (iStack_1f4 == *(int *)puVar2) {
    return (uchar *)piVar6;
  }
  iVar3 = iStack_1f4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  a = PKCS12_new();
  if (a == (PKCS12 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6d,0x41,"p12_init.c",0x46);
  }
  else {
    (*(code *)PTR_ASN1_INTEGER_set_006a7164)(a->version,3);
    pPVar17 = a->authsafes;
    pAVar10 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar3);
    pPVar17->type = pAVar10;
    if (iVar3 == 0x15) {
      pPVar17 = a->authsafes;
      pcVar16 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
      (pPVar17->d).ptr = pcVar16;
      if (pcVar16 != (char *)0x0) {
        return (uchar *)a;
      }
      uVar15 = 0x41;
      uVar11 = 0x4e;
    }
    else {
      uVar15 = 0x77;
      uVar11 = 0x53;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6d,uVar15,"p12_init.c",uVar11);
    PKCS12_free(a);
  }
  return (uchar *)0x0;
}

