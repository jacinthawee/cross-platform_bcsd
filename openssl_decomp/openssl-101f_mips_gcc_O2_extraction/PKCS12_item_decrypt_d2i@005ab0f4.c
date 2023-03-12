
void * PKCS12_item_decrypt_d2i
                 (X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,ASN1_OCTET_STRING *oct,
                 int zbuf)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  PKCS12 *a;
  undefined4 uVar8;
  undefined4 *puVar9;
  ASN1_OBJECT *pAVar10;
  ASN1_OBJECT *pAVar11;
  undefined4 uVar12;
  char *pcVar13;
  PKCS7 *pPVar14;
  int iStack_1a0;
  int iStack_19c;
  undefined auStack_198 [140];
  int iStack_10c;
  undefined *puStack_104;
  ASN1_OBJECT *pAStack_100;
  ASN1_OBJECT *pAStack_fc;
  undefined *puStack_f8;
  ASN1_OBJECT *pAStack_f4;
  char *pcStack_f0;
  ASN1_ITEM *pAStack_ec;
  int iStack_e8;
  code *pcStack_e4;
  undefined *local_d0;
  int local_cc;
  undefined *local_c8;
  undefined local_bc [144];
  undefined4 *local_2c;
  
  puStack_f8 = PTR___stack_chk_guard_006aabf0;
  puStack_104 = local_bc + 4;
  local_c8 = &_gp;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pAStack_fc = (ASN1_OBJECT *)oct->data;
  iStack_e8 = oct->length;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(puStack_104);
  local_cc = 0;
  local_d0 = puStack_104;
  iVar2 = (**(code **)(local_c8 + -0x5ba0))(algor->algorithm,pass,passlen,algor->parameter);
  if (iVar2 == 0) {
    local_d0 = (undefined *)0x53;
    (**(code **)(local_c8 + -0x6eb0))(0x23,0x77,0x73,"p12_decr.c");
LAB_005ab230:
    pcVar13 = "p12_decr.c";
    pAVar11 = (ASN1_OBJECT *)0x75;
    pAVar10 = (ASN1_OBJECT *)&DAT_0000006a;
    local_d0 = (undefined *)0x82;
    (**(code **)(local_c8 + -0x6eb0))(0x23,0x6a,0x75,"p12_decr.c");
    puVar3 = (undefined *)0x0;
  }
  else {
    iVar2 = (**(code **)(local_c8 + -0x6e1c))(puStack_104);
    algor = (X509_ALGOR *)(**(code **)(local_c8 + -0x7dd8))(iStack_e8 + iVar2,"p12_decr.c",0x57);
    if ((ASN1_OBJECT *)algor == (ASN1_OBJECT *)0x0) {
      local_d0 = (undefined *)0x58;
      (**(code **)(local_c8 + -0x6eb0))(0x23,0x77,0x41,"p12_decr.c");
LAB_005ab220:
      (**(code **)(local_c8 + -0x7380))(puStack_104);
      goto LAB_005ab230;
    }
    pass = local_bc;
    local_d0 = (undefined *)iStack_e8;
    iVar2 = (**(code **)(local_c8 + -0x62c0))(puStack_104,algor,pass,pAStack_fc);
    pAVar10 = local_bc._0_4_;
    if (iVar2 == 0) {
      (**(code **)(local_c8 + -0x7f58))(algor);
      local_d0 = (undefined *)0x60;
      (**(code **)(local_c8 + -0x6eb0))(0x23,0x77,6,"p12_decr.c");
      goto LAB_005ab220;
    }
    iVar2 = (**(code **)(local_c8 + -0x62bc))
                      (puStack_104,
                       (undefined *)((int)&(local_bc._0_4_)->sn + (int)&((ASN1_OBJECT *)algor)->sn),
                       pass);
    if (iVar2 == 0) {
      (**(code **)(local_c8 + -0x7f58))(algor);
      local_d0 = (undefined *)0x68;
      (**(code **)(local_c8 + -0x6eb0))(0x23,0x77,0x74,"p12_decr.c");
      pAStack_fc = pAVar10;
      goto LAB_005ab220;
    }
    pAStack_fc = (ASN1_OBJECT *)((int)&(local_bc._0_4_)->sn + (int)&pAVar10->sn);
    (**(code **)(local_c8 + -0x7380))(puStack_104);
    pAVar10 = (ASN1_OBJECT *)pass;
    pAVar11 = pAStack_fc;
    pcVar13 = &it->itype;
    local_bc._0_4_ = (ASN1_OBJECT *)algor;
    puVar3 = (undefined *)(**(code **)(local_c8 + -0x6748))(0,pass,pAStack_fc,it);
    if (zbuf != 0) {
      pAVar10 = pAStack_fc;
      (**(code **)(local_c8 + -0x7d6c))(algor,pAStack_fc);
    }
    if (puVar3 == (undefined *)0x0) {
      pcVar13 = "p12_decr.c";
      pAVar11 = (ASN1_OBJECT *)&DAT_00000065;
      pAVar10 = (ASN1_OBJECT *)&DAT_0000006a;
      local_d0 = (undefined *)0x94;
      (**(code **)(local_c8 + -0x6eb0))(0x23,0x6a,0x65,"p12_decr.c");
    }
    (**(code **)(local_c8 + -0x7f58))(algor);
    puStack_104 = puVar3;
  }
  if (local_2c == *(undefined4 **)puStack_f8) {
    return puVar3;
  }
  pcStack_e4 = PKCS12_item_i2d_encrypt;
  puVar9 = local_2c;
  (**(code **)(local_c8 + -0x5328))();
  iVar2 = (int)local_d0;
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pcStack_f0 = "7 datafinal";
  iStack_1a0 = 0;
  iStack_10c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_100 = (ASN1_OBJECT *)algor;
  pAStack_f4 = (ASN1_OBJECT *)pass;
  pAStack_ec = it;
  piVar4 = (int *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
  if (piVar4 == (int *)0x0) {
    uVar12 = 0x41;
    uVar8 = 0xa5;
  }
  else {
    iVar5 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar2,&iStack_1a0,pAVar10);
    iVar2 = iStack_1a0;
    if (iStack_1a0 != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_198);
      iVar6 = (*(code *)PTR_EVP_PBE_CipherInit_006aa340)
                        (*puVar9,pAVar11,pcVar13,puVar9[1],auStack_198,1);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x73,"p12_decr.c",0x53);
      }
      else {
        iVar6 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(auStack_198);
        iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar5 + iVar6,"p12_decr.c",0x57);
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x41,"p12_decr.c",0x58);
        }
        else {
          iVar7 = (*(code *)PTR_EVP_CipherUpdate_006a9c20)
                            (auStack_198,iVar6,&iStack_19c,iVar2,iVar5);
          iVar2 = iStack_19c;
          if (iVar7 == 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
            (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,6,"p12_decr.c",0x60);
          }
          else {
            iVar7 = (*(code *)PTR_EVP_CipherFinal_ex_006a9c24)
                              (auStack_198,iVar6 + iStack_19c,&iStack_19c);
            puVar1 = PTR_EVP_CIPHER_CTX_cleanup_006a8b60;
            if (iVar7 != 0) {
              piVar4[2] = iVar6;
              *piVar4 = iStack_19c + iVar2;
              (*(code *)puVar1)(auStack_198);
              if (local_cc != 0) {
                (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_1a0,iVar5);
              }
              (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_1a0);
              goto LAB_005ab578;
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
            (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x74,"p12_decr.c",0x68);
          }
        }
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_198);
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6c,0x67,"p12_decr.c",0xaf);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_1a0);
      piVar4 = (int *)0x0;
      goto LAB_005ab578;
    }
    uVar12 = 0x66;
    uVar8 = 0xaa;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6c,uVar12,"p12_decr.c",uVar8);
  piVar4 = (int *)0x0;
LAB_005ab578:
  if (iStack_10c == *(int *)puVar3) {
    return piVar4;
  }
  iVar2 = iStack_10c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  a = PKCS12_new();
  if (a == (PKCS12 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6d,0x41,"p12_init.c",0x45);
  }
  else {
    (*(code *)PTR_ASN1_INTEGER_set_006a8264)(a->version,3);
    pPVar14 = a->authsafes;
    pAVar10 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar2);
    pPVar14->type = pAVar10;
    if (iVar2 == 0x15) {
      pPVar14 = a->authsafes;
      pcVar13 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
      (pPVar14->d).ptr = pcVar13;
      if (pcVar13 != (char *)0x0) {
        return a;
      }
      uVar12 = 0x41;
      uVar8 = 0x4e;
    }
    else {
      uVar12 = 0x77;
      uVar8 = 0x54;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6d,uVar12,"p12_init.c",uVar8);
    PKCS12_free(a);
  }
  return (void *)0x0;
}

