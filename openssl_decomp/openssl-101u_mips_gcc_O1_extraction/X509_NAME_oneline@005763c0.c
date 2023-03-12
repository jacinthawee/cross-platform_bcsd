
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
  undefined4 uVar11;
  X509_REQ *req;
  uchar *puVar12;
  X509_NAME *name;
  ASN1_INTEGER *pAVar13;
  EVP_PKEY **ppEVar14;
  uint uVar15;
  byte *pbVar16;
  EVP_PKEY *pEVar17;
  X509 *a_00;
  char *pkey;
  byte *pbVar18;
  undefined *puVar19;
  ASN1_INTEGER *pAVar20;
  int iVar21;
  X509_REQ_INFO *pXVar22;
  undefined *puVar23;
  uint uVar24;
  EVP_PKEY *pEVar25;
  int local_res8;
  int local_a8;
  char *local_98;
  uint local_8c [4];
  EVP_PKEY aEStack_7c [2];
  X509 *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(X509 **)PTR___stack_chk_guard_006a9ae8;
  if (buf == (char *)0x0) {
    local_a8 = (*(code *)PTR_BUF_MEM_new_006a749c)();
    if (local_a8 != 0) {
      pEVar6 = (EVP_PKEY *)&DAT_000000c8;
      iVar4 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(local_a8);
      if (iVar4 != 0) {
        **(undefined **)(local_a8 + 4) = 0;
        if (a == (X509_NAME *)0x0) {
          iVar4 = 199;
          local_98 = *(char **)(local_a8 + 4);
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_a8);
          size = (int)&DAT_000000c8;
          goto LAB_005768dc;
        }
        local_res8 = 200;
        goto LAB_0057642c;
      }
    }
LAB_0057685c:
    size = (int)&DAT_00000041;
    uVar11 = 0xe2;
LAB_005767f4:
    pkey = &DAT_00000074;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x74,size,"x509_obj.c",uVar11);
    (*(code *)PTR_BUF_MEM_free_006a7494)(local_a8);
    local_98 = (char *)0x0;
  }
  else {
    local_98 = (char *)0x0;
    pkey = buf;
    if (size == 0) goto LAB_0057681c;
    local_a8 = 0;
    pEVar6 = (EVP_PKEY *)buf;
    local_res8 = size;
    if (a == (X509_NAME *)0x0) {
      iVar4 = size + -1;
      local_98 = buf;
LAB_005768dc:
      pkey = "NO X509_NAME";
      (*(code *)PTR_strncpy_006a99e0)(local_98);
      local_98[iVar4] = '\0';
      goto LAB_0057681c;
    }
LAB_0057642c:
    iVar21 = 0;
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(a->entries);
    puVar23 = (undefined *)0x0;
    if (0 < iVar4) {
      do {
        puVar5 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(a->entries,iVar21);
        iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar5);
        if ((iVar4 == 0) ||
           (pEVar6 = (EVP_PKEY *)(*(code *)PTR_OBJ_nid2sn_006a709c)(iVar4),
           pEVar6 == (EVP_PKEY *)0x0)) {
          (*(code *)PTR_i2t_ASN1_OBJECT_006a8c48)(aEStack_7c,0x50,*puVar5);
          pEVar6 = aEStack_7c;
        }
        pEVar7 = (EVP_MD *)(*(code *)PTR_strlen_006a9a24)(pEVar6);
        ppEVar14 = (EVP_PKEY **)puVar5[1];
        pEVar25 = *ppEVar14;
        if (0x100000 < (int)pEVar25) {
          size = 0x86;
          uVar11 = 0x7b;
          goto LAB_005767f4;
        }
        pkey = (char *)ppEVar14[2];
        if ((ppEVar14[1] == (EVP_PKEY *)&DAT_0000001b) &&
           (pEVar10 = (EVP_PKEY *)((uint)pEVar25 & 3), pEVar10 == (EVP_PKEY *)0x0)) {
          local_8c[2] = 0;
          local_8c[1] = 0;
          local_8c[0] = 0;
          pEVar17 = (EVP_PKEY *)pkey;
          if (0 < (int)pEVar25) {
            do {
              if (*(char *)&pEVar17->type != '\0') {
                local_8c[(uint)pEVar10 & 3] = 1;
              }
              pEVar10 = (EVP_PKEY *)((int)&pEVar10->type + 1);
              pEVar17 = (EVP_PKEY *)((int)&pEVar17->type + 1);
            } while (pEVar25 != pEVar10);
            if ((local_8c[0] | local_8c[1] | local_8c[2]) != 0) goto LAB_005764f4;
          }
          local_8c[2] = 0;
          uVar24 = 0;
          local_8c[1] = 0;
          local_8c[0] = 0;
          local_8c[3] = 1;
        }
        else {
LAB_005764f4:
          uVar24 = 1;
          local_8c[3] = 1;
          local_8c[2] = 1;
          local_8c[1] = 1;
          local_8c[0] = 1;
        }
        if ((int)pEVar25 < 1) {
          size = 0;
          puVar19 = (undefined *)((int)&pEVar7->type + 2);
        }
        else {
          uVar15 = 0;
          size = 0;
          uVar8 = uVar24;
          while( true ) {
            if (uVar8 != 0) {
              if ((byte)(*(char *)(int *)pkey - 0x20U) < 0x5f) {
                size = (int)(int *)size + 1;
              }
              else {
                size = size + 4;
              }
            }
            if (pEVar25 == (EVP_PKEY *)(uVar15 + 1)) break;
            pkey = (char *)((int)(int *)pkey + 1);
            uVar15 = uVar15 + 1;
            uVar8 = local_8c[uVar15 & 3];
          }
          pkey = (char *)((int)(int *)pkey + 1);
          puVar19 = (undefined *)((int)&pEVar7->type + 2) + size;
        }
        puVar19 = puVar19 + (int)puVar23;
        if (0x100000 < (int)puVar19) {
          local_8c[3] = 1;
          size = 0x86;
          uVar11 = 0xac;
          goto LAB_005767f4;
        }
        local_8c[3] = 1;
        if (local_a8 == 0) {
          pcVar9 = buf;
          local_98 = buf;
          if (local_res8 <= (int)puVar19) goto LAB_005766d8;
        }
        else {
          iVar4 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(local_a8,puVar19 + 1);
          if (iVar4 == 0) goto LAB_0057685c;
          pcVar9 = *(char **)(local_a8 + 4);
        }
        puVar3 = PTR_memcpy_006a9aec;
        pcVar9[(int)puVar23] = '/';
        size = (int)pEVar7;
        iVar4 = (*(code *)puVar3)(pcVar9 + (int)puVar23 + 1);
        *(undefined *)((int)pEVar7->required_pkey_type + iVar4 + -0x2c) = 0x3d;
        pbVar18 = (byte *)((int)pEVar7->required_pkey_type + iVar4 + -0x2b);
        pbVar16 = *(byte **)(puVar5[1] + 8);
        if (0 < (int)pEVar25) {
          uVar8 = 0;
          while( true ) {
            if (uVar24 != 0) {
              uVar24 = (uint)*pbVar16;
              size = (int)uVar24 >> 4;
              if (uVar24 - 0x20 < 0x5f) {
                *pbVar18 = *pbVar16;
                pbVar18 = pbVar18 + 1;
              }
              else {
                *pbVar18 = 0x5c;
                pbVar18[1] = 0x78;
                pEVar7 = (EVP_MD *)(size + 0x66c55c);
                size = (int)*(byte *)&pEVar7->update;
                bVar1 = "0123456789ABCDEF"[uVar24 & 0xf];
                pbVar18[2] = *(byte *)&pEVar7->update;
                pbVar18[3] = bVar1;
                pbVar18 = pbVar18 + 4;
              }
            }
            pEVar6 = (EVP_PKEY *)(uVar8 + 1);
            if (pEVar25 == pEVar6) break;
            uVar8 = uVar8 + 1;
            pbVar16 = pbVar16 + 1;
            uVar24 = local_8c[uVar8 & 3];
          }
        }
        puVar23 = PTR_sk_num_006a6e2c;
        iVar21 = iVar21 + 1;
        *pbVar18 = 0;
        iVar4 = (*(code *)puVar23)(a->entries);
        puVar23 = puVar19;
      } while (iVar21 < iVar4);
    }
    pkey = (char *)pEVar6;
    local_98 = buf;
    if (local_a8 != 0) {
      local_98 = *(char **)(local_a8 + 4);
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_a8);
      pkey = (char *)pEVar6;
    }
LAB_005766d8:
    if (iVar21 == 0) {
      *local_98 = '\0';
    }
  }
LAB_0057681c:
  if (local_2c == *(X509 **)puVar2) {
    return local_98;
  }
  a_00 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  req = (X509_REQ *)(*(code *)PTR_X509_REQ_new_006a6ed0)();
  puVar2 = PTR_CRYPTO_malloc_006a7008;
  if (req == (X509_REQ *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7e,0x41,"x509_req.c",0x4f);
  }
  else {
    pXVar22 = req->req_info;
    pAVar20 = pXVar22->version;
    pAVar20->length = 1;
    puVar12 = (uchar *)(*(code *)puVar2)(1,"x509_req.c",0x56);
    pAVar13 = pXVar22->version;
    pAVar20->data = puVar12;
    puVar12 = pAVar13->data;
    if (puVar12 != (uchar *)0x0) {
      *puVar12 = '\0';
      name = X509_get_subject_name(a_00);
      iVar4 = X509_REQ_set_subject_name(req,name);
      if ((iVar4 != 0) && (pEVar6 = X509_get_pubkey(a_00), pEVar6 != (EVP_PKEY *)0x0)) {
        iVar4 = X509_REQ_set_pubkey(req,pEVar6);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar6);
        if ((iVar4 != 0) &&
           (((EVP_PKEY *)pkey == (EVP_PKEY *)0x0 ||
            (iVar4 = X509_REQ_sign(req,(EVP_PKEY *)pkey,(EVP_MD *)size), iVar4 != 0)))) {
          return (char *)req;
        }
      }
    }
  }
  (*(code *)PTR_X509_REQ_free_006a6e8c)(req);
  return (char *)0x0;
}

