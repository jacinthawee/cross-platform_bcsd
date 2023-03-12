
uint x509v3_cache_extensions_part_6(X509 *param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  EVP_MD *type;
  X509_NAME *pXVar4;
  X509_NAME *b;
  int iVar5;
  int *piVar6;
  PROXY_CERT_INFO_EXTENSION *a;
  uint uVar7;
  long lVar8;
  void *pvVar9;
  undefined4 uVar10;
  ASN1_OCTET_STRING *pAVar11;
  AUTHORITY_KEYID *pAVar12;
  stack_st_GENERAL_NAME *psVar13;
  NAME_CONSTRAINTS *pNVar14;
  stack_st_DIST_POINT *psVar15;
  DIST_POINT_NAME **ppDVar16;
  DIST_POINT_NAME *pDVar17;
  X509_EXTENSION *ex;
  ASN1_OBJECT *pAVar18;
  int iVar19;
  byte *pbVar20;
  uint uVar21;
  int iVar22;
  ulong uVar23;
  undefined1 *puVar24;
  int iVar25;
  undefined1 *local_34;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  type = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
  X509_digest(param_1,type,(uchar *)&param_1->rfc3779_addr,(uint *)0x0);
  pXVar4 = X509_get_subject_name(param_1);
  b = X509_get_issuer_name(param_1);
  iVar5 = X509_NAME_cmp(pXVar4,b);
  if (iVar5 == 0) {
    param_1->ex_flags = param_1->ex_flags | 0x20;
  }
  iVar5 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(param_1->cert_info->version);
  if (iVar5 == 0) {
    param_1->ex_flags = param_1->ex_flags | 0x40;
  }
  piVar6 = (int *)X509_get_ext_d2i(param_1,0x57,(int *)0x0,(int *)0x0);
  if (piVar6 != (int *)0x0) {
    iVar5 = *piVar6;
    if (iVar5 == 0) {
      iVar22 = piVar6[1];
      if (iVar22 == 0) goto LAB_0059453c;
LAB_00593ef8:
      if ((*(int *)(iVar22 + 4) == 0x102) || (iVar5 == 0)) {
        param_1->ex_pathlen = 0;
        param_1->ex_flags = param_1->ex_flags | 0x80;
      }
      else {
        lVar8 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)();
        param_1->ex_pathlen = lVar8;
      }
    }
    else {
      iVar22 = piVar6[1];
      param_1->ex_flags = param_1->ex_flags | 0x10;
      if (iVar22 != 0) goto LAB_00593ef8;
LAB_0059453c:
      param_1->ex_pathlen = -1;
    }
    (*(code *)PTR_BASIC_CONSTRAINTS_free_006a9074)(piVar6);
    param_1->ex_flags = param_1->ex_flags | 1;
  }
  a = (PROXY_CERT_INFO_EXTENSION *)X509_get_ext_d2i(param_1,0x297,(int *)0x0,(int *)0x0);
  if (a == (PROXY_CERT_INFO_EXTENSION *)0x0) goto LAB_00593fb0;
  uVar7 = param_1->ex_flags;
  if ((uVar7 & 0x10) == 0) {
    iVar5 = X509_get_ext_by_NID(param_1,0x55,-1);
    if (-1 < iVar5) {
      uVar7 = param_1->ex_flags;
      goto LAB_00593f70;
    }
    iVar5 = X509_get_ext_by_NID(param_1,0x56,-1);
    if (-1 < iVar5) {
      uVar7 = param_1->ex_flags;
      goto LAB_00593f70;
    }
  }
  else {
LAB_00593f70:
    param_1->ex_flags = uVar7 | 0x80;
  }
  if (a->pcPathLengthConstraint == (ASN1_INTEGER *)0x0) {
    param_1->ex_pcpathlen = -1;
  }
  else {
    lVar8 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)();
    param_1->ex_pcpathlen = lVar8;
  }
  PROXY_CERT_INFO_EXTENSION_free(a);
  param_1->ex_flags = param_1->ex_flags | 0x400;
LAB_00593fb0:
  piVar6 = (int *)X509_get_ext_d2i(param_1,0x53,(int *)0x0,(int *)0x0);
  if (piVar6 != (int *)0x0) {
    iVar5 = *piVar6;
    if (iVar5 < 1) {
      param_1->ex_kusage = 0;
    }
    else {
      pbVar20 = (byte *)piVar6[2];
      bVar1 = *pbVar20;
      param_1->ex_kusage = (uint)bVar1;
      if (iVar5 != 1) {
        param_1->ex_kusage = (uint)CONCAT11(pbVar20[1],bVar1);
      }
    }
    puVar2 = PTR_ASN1_BIT_STRING_free_006a8670;
    param_1->ex_flags = param_1->ex_flags | 2;
    (*(code *)puVar2)(piVar6);
  }
  param_1->ex_xkusage = 0;
  pvVar9 = X509_get_ext_d2i(param_1,0x7e,(int *)0x0,(int *)0x0);
  if (pvVar9 != (void *)0x0) {
    local_34 = (undefined1 *)0x0;
    param_1->ex_flags = param_1->ex_flags | 4;
    while (iVar5 = (*(code *)PTR_sk_num_006a6e2c)(pvVar9), (int)local_34 < iVar5) {
      uVar10 = (*(code *)PTR_sk_value_006a6e24)(pvVar9);
      iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uVar10);
      if (iVar5 == 0x85) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x40;
      }
      else if (iVar5 < 0x86) {
        if (iVar5 == 0x82) {
          param_1->ex_xkusage = param_1->ex_xkusage | 2;
        }
        else if (iVar5 < 0x83) {
          if (iVar5 == 0x81) {
            param_1->ex_xkusage = param_1->ex_xkusage | 1;
          }
        }
        else if (iVar5 == 0x83) {
          param_1->ex_xkusage = param_1->ex_xkusage | 8;
        }
        else if (iVar5 == 0x84) {
          param_1->ex_xkusage = param_1->ex_xkusage | 4;
        }
      }
      else if (iVar5 == 0x8b) {
LAB_00594510:
        param_1->ex_xkusage = param_1->ex_xkusage | 0x10;
      }
      else if (iVar5 < 0x8c) {
        if (iVar5 == 0x89) goto LAB_00594510;
      }
      else if (iVar5 == 0xb4) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x20;
      }
      else if (iVar5 == 0x129) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x80;
      }
      local_34 = local_34 + 1;
    }
    (*(code *)PTR_sk_pop_free_006a7058)(pvVar9,PTR_ASN1_OBJECT_free_006a7004);
  }
  piVar6 = (int *)X509_get_ext_d2i(param_1,0x47,(int *)0x0,(int *)0x0);
  puVar2 = PTR_ASN1_BIT_STRING_free_006a8670;
  if (piVar6 != (int *)0x0) {
    uVar23 = 0;
    if (0 < *piVar6) {
      uVar23 = (ulong)*(byte *)piVar6[2];
    }
    param_1->ex_nscert = uVar23;
    param_1->ex_flags = param_1->ex_flags | 8;
    (*(code *)puVar2)(piVar6);
  }
  pAVar11 = (ASN1_OCTET_STRING *)X509_get_ext_d2i(param_1,0x52,(int *)0x0,(int *)0x0);
  param_1->skid = pAVar11;
  pAVar12 = (AUTHORITY_KEYID *)X509_get_ext_d2i(param_1,0x5a,(int *)0x0,(int *)0x0);
  param_1->akid = pAVar12;
  psVar13 = (stack_st_GENERAL_NAME *)X509_get_ext_d2i(param_1,0x55,(int *)0x0,(int *)0x0);
  param_1->altname = psVar13;
  pNVar14 = (NAME_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x29a,(int *)&local_34,(int *)0x0);
  param_1->nc = pNVar14;
  if ((pNVar14 == (NAME_CONSTRAINTS *)0x0) && (local_34 != (undefined1 *)0xffffffff)) {
    param_1->ex_flags = param_1->ex_flags | 0x80;
  }
  iVar22 = 0;
  psVar15 = (stack_st_DIST_POINT *)X509_get_ext_d2i(param_1,0x67,(int *)0x0,(int *)0x0);
  iVar25 = 0;
  param_1->crldp = psVar15;
  iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar15);
  if (0 < iVar5) {
    do {
      ppDVar16 = (DIST_POINT_NAME **)(*(code *)PTR_sk_value_006a6e24)(param_1->crldp,iVar25);
      pDVar17 = ppDVar16[1];
      if (pDVar17 == (DIST_POINT_NAME *)0x0) {
        ppDVar16[3] = (DIST_POINT_NAME *)0x807f;
      }
      else {
        iVar5 = pDVar17->type;
        if (iVar5 < 1) {
          pDVar17 = ppDVar16[3];
        }
        else {
          pXVar4 = pDVar17->dpname;
          bVar1 = *(byte *)&pXVar4->entries;
          pDVar17 = (DIST_POINT_NAME *)(uint)bVar1;
          ppDVar16[3] = pDVar17;
          if (iVar5 != 1) {
            pDVar17 = (DIST_POINT_NAME *)
                      (uint)CONCAT11(*(undefined *)((int)&pXVar4->entries + 1),bVar1);
          }
        }
        ppDVar16[3] = (DIST_POINT_NAME *)((uint)pDVar17 & 0x807f);
      }
      if ((*ppDVar16 == (DIST_POINT_NAME *)0x0) || ((*ppDVar16)->type != 1)) {
        psVar15 = param_1->crldp;
      }
      else {
        for (iVar5 = 0; iVar19 = (*(code *)PTR_sk_num_006a6e2c)(ppDVar16[2]), iVar5 < iVar19;
            iVar5 = iVar5 + 1) {
          piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(ppDVar16[2],iVar5);
          if (*piVar6 == 4) {
            pXVar4 = (X509_NAME *)piVar6[1];
            if (pXVar4 != (X509_NAME *)0x0) goto LAB_0059444c;
            break;
          }
        }
        pXVar4 = X509_get_issuer_name(param_1);
LAB_0059444c:
        DIST_POINT_set_dpname(*ppDVar16,pXVar4);
        psVar15 = param_1->crldp;
      }
      iVar25 = iVar25 + 1;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar15);
    } while (iVar25 < iVar5);
  }
  local_34 = (undefined1 *)0x0;
  do {
    iVar5 = X509_get_ext_count(param_1);
    puVar24 = local_34;
    if (iVar5 <= (int)local_34) {
      uVar7 = param_1->ex_flags;
LAB_005943b8:
      iVar5 = *(int *)puVar3;
      param_1->ex_flags = uVar7 | 0x100;
      if (local_2c == iVar5) {
        return uVar7 | 0x100;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      if (iVar22 == 0) {
        return 1;
      }
      uVar7 = *(uint *)(puVar24 + 0x28);
      if (((uVar7 & 2) == 0) || ((*(uint *)(puVar24 + 0x2c) & 4) != 0)) {
        if ((uVar7 & 1) != 0) {
          return (uVar7 << 0x1b) >> 0x1f;
        }
        if ((uVar7 & 0x60) == 0x60) {
          return 3;
        }
        if ((uVar7 & 2) != 0) {
          return 4;
        }
        uVar21 = 5;
        if ((uVar7 & 8) != 0) {
          if ((*(uint *)(puVar24 + 0x34) & 7) == 0) {
            uVar21 = 0;
          }
          return uVar21;
        }
      }
      return 0;
    }
    ex = X509_get_ext(param_1,(int)local_34);
    pAVar18 = X509_EXTENSION_get_object(ex);
    iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar18);
    if (iVar5 == 0x359) {
      param_1->ex_flags = param_1->ex_flags | 0x1000;
    }
    iVar5 = X509_EXTENSION_get_critical(ex);
    if (iVar5 != 0) {
      pAVar18 = X509_EXTENSION_get_object(ex);
      local_30 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar18);
      if (local_30 == 0) {
        uVar7 = param_1->ex_flags;
      }
      else {
        iVar22 = 0xb;
        puVar24 = supported_nids_13639;
        iVar5 = (*(code *)PTR_OBJ_bsearch__006a8368)
                          (&local_30,supported_nids_13639,0xb,4,nid_cmp_BSEARCH_CMP_FN);
        if (iVar5 != 0) goto LAB_00594310;
        uVar7 = param_1->ex_flags;
      }
      uVar7 = uVar7 | 0x200;
      goto LAB_005943b8;
    }
LAB_00594310:
    local_34 = local_34 + 1;
  } while( true );
}

