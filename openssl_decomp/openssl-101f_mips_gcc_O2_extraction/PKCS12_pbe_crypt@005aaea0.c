
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
  
  puStack_104 = PTR___stack_chk_guard_006aabf0;
  puStack_108 = auStack_b8;
  local_d0 = &_gp;
  local_2c = *(undefined4 *****)PTR___stack_chk_guard_006aabf0;
  local_c8 = passlen;
  local_c4 = pass;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(puStack_108);
  local_d4 = en_de;
  local_d8 = (int *)puStack_108;
  iVar3 = (**(code **)(local_d0 + -0x5ba0))(algor->algorithm,local_c4,local_c8,algor->parameter);
  if (iVar3 == 0) {
    ppppuStack_1dc = (undefined4 ****)&DAT_00000073;
    pcVar16 = "p12_decr.c";
    local_d8 = (int *)0x53;
    puStack_1d4 = &DAT_00000077;
    (**(code **)(local_d0 + -0x6eb0))(0x23,0x77,0x73,"p12_decr.c");
    pXVar4 = (X509_ALGOR *)0x0;
  }
  else {
    unaff_s4 = "7 datafinal";
    iVar3 = (**(code **)(local_d0 + -0x6e1c))(puStack_108);
    pXVar4 = (X509_ALGOR *)(**(code **)(local_d0 + -0x7dd8))(iVar3 + inlen,"p12_decr.c",0x57);
    if (pXVar4 == (X509_ALGOR *)0x0) {
      pcVar16 = "p12_decr.c";
      ppppuStack_1dc = (undefined4 ****)&DAT_00000041;
      puStack_1d4 = &DAT_00000077;
      local_d8 = (int *)0x58;
      (**(code **)(local_d0 + -0x6eb0))(0x23,0x77,0x41,"p12_decr.c");
LAB_005aafd8:
      pcVar19 = *(code **)(local_d0 + -0x7380);
    }
    else {
      ppppuStack_1dc = &local_bc;
      local_d8 = (int *)inlen;
      pcVar16 = (char *)in;
      iVar3 = (**(code **)(local_d0 + -0x62c0))(puStack_108,pXVar4,ppppuStack_1dc,in);
      pppuVar18 = local_bc;
      if (iVar3 == 0) {
        (**(code **)(local_d0 + -0x7f58))(pXVar4);
        ppppuStack_1dc = (undefined4 ****)&DAT_00000006;
        local_d8 = (int *)&DAT_00000060;
        pcVar19 = *(code **)(local_d0 + -0x6eb0);
        pppuVar18 = (undefined4 ***)inlen;
LAB_005aafc4:
        pcVar16 = "p12_decr.c";
        puStack_1d4 = &DAT_00000077;
        pXVar4 = (X509_ALGOR *)0x0;
        (*pcVar19)(0x23,0x77,ppppuStack_1dc,"p12_decr.c");
        inlen = (int)pppuVar18;
        goto LAB_005aafd8;
      }
      puStack_1d4 = (uchar *)((int)&pXVar4->algorithm + (int)local_bc);
      iVar3 = (**(code **)(local_d0 + -0x62bc))(puStack_108);
      if (iVar3 == 0) {
        (**(code **)(local_d0 + -0x7f58))(pXVar4);
        ppppuStack_1dc = (undefined4 ****)&DAT_00000074;
        local_d8 = (int *)&DAT_00000068;
        pcVar19 = *(code **)(local_d0 + -0x6eb0);
        goto LAB_005aafc4;
      }
      inlen = (int)pppuVar18 + (int)local_bc;
      if (datalen != (int *)0x0) {
        *datalen = inlen;
      }
      pcVar19 = *(code **)(local_d0 + -0x7380);
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
  (**(code **)(local_d0 + -0x5328))();
  puStack_1e0 = PTR___stack_chk_guard_006aabf0;
  piStack_f0 = datalen;
  ppuStack_f4 = data;
  puStack_1b0 = &_gp;
  puStack_114 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  ppppuStack_1e4 = (undefined4 ****)local_d8[2];
  iStack_1d0 = *local_d8;
  pXStack_10c = algor;
  pppuStack_100 = (undefined4 ***)inlen;
  pcStack_fc = unaff_s4;
  puStack_f8 = in;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_1a0);
  iStack_1b4 = 0;
  puStack_1b8 = auStack_1a0;
  iVar3 = (**(code **)(puStack_1b0 + -0x5ba0))
                    (*ppppuStack_1e8,ppppuStack_1dc,pcVar16,ppppuStack_1e8[1]);
  if (iVar3 == 0) {
    puStack_1b8 = (uchar *)0x53;
    (**(code **)(puStack_1b0 + -0x6eb0))(0x23,0x77,0x73,"p12_decr.c");
LAB_005ab230:
    pcVar16 = "p12_decr.c";
    ppppuVar14 = (undefined4 ****)0x75;
    ppppuVar13 = (undefined4 ****)&DAT_0000006a;
    puStack_1b8 = (uchar *)0x82;
    (**(code **)(puStack_1b0 + -0x6eb0))(0x23,0x6a,0x75,"p12_decr.c");
    puVar5 = (uchar *)0x0;
    puStack_1ec = auStack_1a0;
  }
  else {
    iVar3 = (**(code **)(puStack_1b0 + -0x6e1c))(auStack_1a0);
    ppppuStack_1e8 =
         (undefined4 ****)(**(code **)(puStack_1b0 + -0x7dd8))(iStack_1d0 + iVar3,"p12_decr.c",0x57)
    ;
    if (ppppuStack_1e8 == (undefined4 ****)0x0) {
      puStack_1b8 = (uchar *)0x58;
      (**(code **)(puStack_1b0 + -0x6eb0))(0x23,0x77,0x41,"p12_decr.c");
LAB_005ab220:
      (**(code **)(puStack_1b0 + -0x7380))(auStack_1a0);
      goto LAB_005ab230;
    }
    ppppuStack_1dc = &ppppuStack_1a4;
    puStack_1b8 = (uchar *)iStack_1d0;
    iVar3 = (**(code **)(puStack_1b0 + -0x62c0))
                      (auStack_1a0,ppppuStack_1e8,ppppuStack_1dc,ppppuStack_1e4);
    ppppuVar13 = ppppuStack_1a4;
    if (iVar3 == 0) {
      (**(code **)(puStack_1b0 + -0x7f58))(ppppuStack_1e8);
      puStack_1b8 = (uchar *)0x60;
      (**(code **)(puStack_1b0 + -0x6eb0))(0x23,0x77,6,"p12_decr.c");
      goto LAB_005ab220;
    }
    iVar3 = (**(code **)(puStack_1b0 + -0x62bc))
                      (auStack_1a0,(undefined *)((int)ppppuStack_1e8 + (int)ppppuStack_1a4),
                       ppppuStack_1dc);
    if (iVar3 == 0) {
      (**(code **)(puStack_1b0 + -0x7f58))(ppppuStack_1e8);
      puStack_1b8 = (uchar *)0x68;
      (**(code **)(puStack_1b0 + -0x6eb0))(0x23,0x77,0x74,"p12_decr.c");
      ppppuStack_1e4 = ppppuVar13;
      goto LAB_005ab220;
    }
    ppppuStack_1e4 = (undefined4 ****)((int)ppppuVar13 + (int)ppppuStack_1a4);
    (**(code **)(puStack_1b0 + -0x7380))(auStack_1a0);
    ppppuVar13 = ppppuStack_1dc;
    ppppuVar14 = ppppuStack_1e4;
    pcVar16 = (char *)puStack_1d4;
    ppppuStack_1a4 = ppppuStack_1e8;
    puVar5 = (uchar *)(**(code **)(puStack_1b0 + -0x6748))
                                (0,ppppuStack_1dc,ppppuStack_1e4,puStack_1d4);
    if (local_d4 != 0) {
      ppppuVar13 = ppppuStack_1e4;
      (**(code **)(puStack_1b0 + -0x7d6c))(ppppuStack_1e8,ppppuStack_1e4);
    }
    if (puVar5 == (uchar *)0x0) {
      pcVar16 = "p12_decr.c";
      ppppuVar14 = (undefined4 ****)&DAT_00000065;
      ppppuVar13 = (undefined4 ****)&DAT_0000006a;
      puStack_1b8 = (uchar *)0x94;
      (**(code **)(puStack_1b0 + -0x6eb0))(0x23,0x6a,0x65,"p12_decr.c");
    }
    (**(code **)(puStack_1b0 + -0x7f58))(ppppuStack_1e8);
    puStack_1ec = puVar5;
  }
  if (puStack_114 == *(undefined4 **)puStack_1e0) {
    return puVar5;
  }
  pcStack_1cc = PKCS12_item_i2d_encrypt;
  puVar12 = puStack_114;
  (**(code **)(puStack_1b0 + -0x5328))();
  iVar3 = (int)puStack_1b8;
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pcStack_1d8 = "7 datafinal";
  iStack_288 = 0;
  iStack_1f4 = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar6 = (int *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
  if (piVar6 == (int *)0x0) {
    uVar15 = 0x41;
    uVar11 = 0xa5;
  }
  else {
    iVar7 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar3,&iStack_288,ppppuVar13);
    iVar3 = iStack_288;
    if (iStack_288 != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_280);
      iVar8 = (*(code *)PTR_EVP_PBE_CipherInit_006aa340)
                        (*puVar12,ppppuVar14,pcVar16,puVar12[1],auStack_280,1);
      if (iVar8 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x73,"p12_decr.c",0x53);
      }
      else {
        iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(auStack_280);
        iVar8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar7 + iVar8,"p12_decr.c",0x57);
        if (iVar8 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x41,"p12_decr.c",0x58);
        }
        else {
          iVar9 = (*(code *)PTR_EVP_CipherUpdate_006a9c20)
                            (auStack_280,iVar8,&iStack_284,iVar3,iVar7);
          iVar3 = iStack_284;
          if (iVar9 == 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(iVar8);
            (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,6,"p12_decr.c",0x60);
          }
          else {
            iVar9 = (*(code *)PTR_EVP_CipherFinal_ex_006a9c24)
                              (auStack_280,iVar8 + iStack_284,&iStack_284);
            puVar1 = PTR_EVP_CIPHER_CTX_cleanup_006a8b60;
            if (iVar9 != 0) {
              piVar6[2] = iVar8;
              *piVar6 = iStack_284 + iVar3;
              (*(code *)puVar1)(auStack_280);
              if (iStack_1b4 != 0) {
                (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_288,iVar7);
              }
              (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_288);
              goto LAB_005ab578;
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(iVar8);
            (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x74,"p12_decr.c",0x68);
          }
        }
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_280);
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6c,0x67,"p12_decr.c",0xaf);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_288);
      piVar6 = (int *)0x0;
      goto LAB_005ab578;
    }
    uVar15 = 0x66;
    uVar11 = 0xaa;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6c,uVar15,"p12_decr.c",uVar11);
  piVar6 = (int *)0x0;
LAB_005ab578:
  if (iStack_1f4 == *(int *)puVar2) {
    return (uchar *)piVar6;
  }
  iVar3 = iStack_1f4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  a = PKCS12_new();
  if (a == (PKCS12 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6d,0x41,"p12_init.c",0x45);
  }
  else {
    (*(code *)PTR_ASN1_INTEGER_set_006a8264)(a->version,3);
    pPVar17 = a->authsafes;
    pAVar10 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar3);
    pPVar17->type = pAVar10;
    if (iVar3 == 0x15) {
      pPVar17 = a->authsafes;
      pcVar16 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
      (pPVar17->d).ptr = pcVar16;
      if (pcVar16 != (char *)0x0) {
        return (uchar *)a;
      }
      uVar15 = 0x41;
      uVar11 = 0x4e;
    }
    else {
      uVar15 = 0x77;
      uVar11 = 0x54;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6d,uVar15,"p12_init.c",uVar11);
    PKCS12_free(a);
  }
  return (uchar *)0x0;
}

