
char * X509_NAME_oneline(X509_NAME *a,char *buf,int size)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  EVP_PKEY *pEVar6;
  EVP_MD *pEVar7;
  uint uVar8;
  char *pcVar9;
  EVP_PKEY *pEVar10;
  X509_REQ *req;
  uchar *puVar11;
  X509_NAME *name;
  ASN1_INTEGER *pAVar12;
  EVP_PKEY **ppEVar13;
  uint uVar14;
  byte *pbVar15;
  EVP_PKEY *pEVar16;
  X509 *a_00;
  char *pkey;
  byte *pbVar17;
  undefined *puVar18;
  ASN1_INTEGER *pAVar19;
  X509_REQ_INFO *pXVar20;
  int iVar21;
  undefined *puVar22;
  uint uVar23;
  EVP_PKEY *pEVar24;
  int local_res8;
  int local_a8;
  char *local_98;
  uint local_8c [4];
  EVP_PKEY aEStack_7c [2];
  X509 *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(X509 **)PTR___stack_chk_guard_006aabf0;
  local_98 = buf;
  if (buf == (char *)0x0) {
    local_a8 = (*(code *)PTR_BUF_MEM_new_006a859c)();
    if (local_a8 == 0) {
      size = (int)&DAT_00000041;
      pkey = &DAT_00000074;
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x74,0x41,"x509_obj.c",0xde);
      local_98 = (char *)0x0;
      goto LAB_00579e80;
    }
    pEVar6 = (EVP_PKEY *)&DAT_000000c8;
    iVar4 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(local_a8);
    if (iVar4 == 0) {
LAB_00579fbc:
      size = (int)&DAT_00000041;
      pkey = &DAT_00000074;
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x74,0x41,"x509_obj.c",0xde);
      (*(code *)PTR_BUF_MEM_free_006a8594)(local_a8);
      local_98 = (char *)0x0;
      goto LAB_00579e80;
    }
    **(undefined **)(local_a8 + 4) = 0;
    if (a == (X509_NAME *)0x0) {
      iVar4 = 199;
      local_98 = *(char **)(local_a8 + 4);
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_a8);
      size = (int)&DAT_000000c8;
      goto LAB_0057a034;
    }
    local_res8 = 200;
  }
  else {
    local_a8 = 0;
    pEVar6 = (EVP_PKEY *)buf;
    local_res8 = size;
    if (a == (X509_NAME *)0x0) {
      iVar4 = size + -1;
LAB_0057a034:
      pkey = "NO X509_NAME";
      (*(code *)PTR_strncpy_006aaaec)(local_98);
      local_98[iVar4] = '\0';
      goto LAB_00579e80;
    }
  }
  iVar21 = 0;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a->entries);
  puVar22 = (undefined *)0x0;
  if (0 < iVar4) {
    do {
      puVar5 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(a->entries,iVar21);
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar5);
      if ((iVar4 == 0) ||
         (pEVar6 = (EVP_PKEY *)(*(code *)PTR_OBJ_nid2sn_006a819c)(iVar4), pEVar6 == (EVP_PKEY *)0x0)
         ) {
        (*(code *)PTR_i2t_ASN1_OBJECT_006a9d64)(aEStack_7c,0x50,*puVar5);
        pEVar6 = aEStack_7c;
      }
      pEVar7 = (EVP_MD *)(*(code *)PTR_strlen_006aab30)(pEVar6);
      ppEVar13 = (EVP_PKEY **)puVar5[1];
      pEVar24 = *ppEVar13;
      pkey = (char *)ppEVar13[2];
      if ((ppEVar13[1] == (EVP_PKEY *)&DAT_0000001b) &&
         (pEVar10 = (EVP_PKEY *)((uint)pEVar24 & 3), pEVar10 == (EVP_PKEY *)0x0)) {
        local_8c[2] = 0;
        local_8c[1] = 0;
        local_8c[0] = 0;
        pEVar16 = (EVP_PKEY *)pkey;
        if (0 < (int)pEVar24) {
          do {
            if (*(char *)&pEVar16->type != '\0') {
              local_8c[(uint)pEVar10 & 3] = 1;
            }
            pEVar10 = (EVP_PKEY *)((int)&pEVar10->type + 1);
            pEVar16 = (EVP_PKEY *)((int)&pEVar16->type + 1);
          } while (pEVar24 != pEVar10);
          if ((local_8c[0] | local_8c[1] | local_8c[2]) != 0) goto LAB_00579c94;
        }
        uVar23 = 0;
        local_8c[2] = 0;
        local_8c[1] = 0;
        local_8c[0] = 0;
        local_8c[3] = 1;
      }
      else {
LAB_00579c94:
        local_8c[3] = 1;
        uVar23 = 1;
        local_8c[2] = 1;
        local_8c[1] = 1;
        local_8c[0] = 1;
      }
      if ((int)pEVar24 < 1) {
        size = 0;
      }
      else {
        uVar14 = 0;
        size = 0;
        uVar8 = uVar23;
        pEVar10 = (EVP_PKEY *)pkey;
        while( true ) {
          if (uVar8 != 0) {
            if ((byte)(*(char *)&pEVar10->type - 0x20U) < 0x5f) {
              size = (int)(int *)size + 1;
            }
            else {
              size = size + 4;
            }
          }
          pkey = (char *)((int)&pEVar10->type + 1);
          if (pEVar24 == (EVP_PKEY *)(uVar14 + 1)) break;
          pEVar10 = (EVP_PKEY *)((int)&pEVar10->type + 1);
          uVar14 = uVar14 + 1;
          uVar8 = local_8c[uVar14 & 3];
        }
      }
      local_8c[3] = 1;
      puVar18 = (undefined *)((int)&pEVar7->type + 2) + size + (int)puVar22;
      if (local_a8 == 0) {
        pcVar9 = buf;
        if (local_res8 <= (int)puVar18) goto LAB_00579e78;
      }
      else {
        iVar4 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(local_a8,puVar18 + 1);
        if (iVar4 == 0) goto LAB_00579fbc;
        pcVar9 = *(char **)(local_a8 + 4);
      }
      puVar3 = PTR_memcpy_006aabf4;
      pcVar9[(int)puVar22] = '/';
      size = (int)pEVar7;
      iVar4 = (*(code *)puVar3)(pcVar9 + (int)puVar22 + 1);
      *(undefined *)((int)pEVar7->required_pkey_type + iVar4 + -0x2c) = 0x3d;
      pbVar17 = (byte *)((int)pEVar7->required_pkey_type + iVar4 + -0x2b);
      pbVar15 = *(byte **)(puVar5[1] + 8);
      if (0 < (int)pEVar24) {
        uVar8 = 0;
        while( true ) {
          if (uVar23 != 0) {
            uVar23 = (uint)*pbVar15;
            size = (int)uVar23 >> 4;
            if (uVar23 - 0x20 < 0x5f) {
              *pbVar17 = *pbVar15;
              pbVar17 = pbVar17 + 1;
            }
            else {
              *pbVar17 = 0x5c;
              pbVar17[1] = 0x78;
              pEVar7 = (EVP_MD *)(size + 0x66cf28);
              size = (int)*(byte *)(pEVar7->required_pkey_type + 3);
              bVar1 = "0123456789ABCDEF"[uVar23 & 0xf];
              pbVar17[2] = *(byte *)(pEVar7->required_pkey_type + 3);
              pbVar17[3] = bVar1;
              pbVar17 = pbVar17 + 4;
            }
          }
          pEVar6 = (EVP_PKEY *)(uVar8 + 1);
          if (pEVar24 == pEVar6) break;
          uVar8 = uVar8 + 1;
          pbVar15 = pbVar15 + 1;
          uVar23 = local_8c[uVar8 & 3];
        }
      }
      puVar22 = PTR_sk_num_006a7f2c;
      iVar21 = iVar21 + 1;
      *pbVar17 = 0;
      iVar4 = (*(code *)puVar22)(a->entries);
      puVar22 = puVar18;
    } while (iVar21 < iVar4);
  }
  pkey = (char *)pEVar6;
  if (local_a8 != 0) {
    local_98 = *(char **)(local_a8 + 4);
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_a8);
    pkey = (char *)pEVar6;
  }
LAB_00579e78:
  if (iVar21 == 0) {
    *local_98 = '\0';
  }
LAB_00579e80:
  if (local_2c == *(X509 **)puVar2) {
    return local_98;
  }
  a_00 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  req = (X509_REQ *)(*(code *)PTR_X509_REQ_new_006a7fd0)();
  puVar2 = PTR_CRYPTO_malloc_006a8108;
  if (req == (X509_REQ *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7e,0x41,"x509_req.c",0x50);
  }
  else {
    pXVar20 = req->req_info;
    pAVar19 = pXVar20->version;
    pAVar19->length = 1;
    puVar11 = (uchar *)(*(code *)puVar2)(1,"x509_req.c",0x57);
    pAVar12 = pXVar20->version;
    pAVar19->data = puVar11;
    puVar11 = pAVar12->data;
    if (puVar11 != (uchar *)0x0) {
      *puVar11 = '\0';
      name = X509_get_subject_name(a_00);
      iVar4 = X509_REQ_set_subject_name(req,name);
      if (iVar4 != 0) {
        pEVar6 = X509_get_pubkey(a_00);
        iVar4 = X509_REQ_set_pubkey(req,pEVar6);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(pEVar6);
        if ((iVar4 != 0) &&
           (((EVP_PKEY *)pkey == (EVP_PKEY *)0x0 ||
            (iVar4 = X509_REQ_sign(req,(EVP_PKEY *)pkey,(EVP_MD *)size), iVar4 != 0)))) {
          return (char *)req;
        }
      }
    }
  }
  (*(code *)PTR_X509_REQ_free_006a7f8c)(req);
  return (char *)0x0;
}

