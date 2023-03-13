
void __regparm3 x509v3_cache_extensions_part_6(X509 *param_1)

{
  byte bVar1;
  byte *pbVar2;
  ASN1_INTEGER *a;
  EVP_MD *type;
  X509_NAME *pXVar3;
  X509_NAME *a_00;
  int iVar4;
  long lVar5;
  BASIC_CONSTRAINTS *a_01;
  PROXY_CERT_INFO_EXTENSION *a_02;
  uint uVar6;
  ASN1_BIT_STRING *pAVar7;
  _STACK *p_Var8;
  ASN1_OBJECT *pAVar9;
  ASN1_OCTET_STRING *pAVar10;
  AUTHORITY_KEYID *pAVar11;
  stack_st_GENERAL_NAME *psVar12;
  NAME_CONSTRAINTS *pNVar13;
  int iVar14;
  DIST_POINT_NAME **ppDVar15;
  DIST_POINT_NAME *pDVar16;
  int *piVar17;
  int iVar18;
  X509_EXTENSION *ex;
  void *pvVar19;
  ulong uVar20;
  int in_GS_OFFSET;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = EVP_sha1();
  X509_digest(param_1,type,(uchar *)&param_1->rfc3779_addr,(uint *)0x0);
  pXVar3 = X509_get_issuer_name(param_1);
  a_00 = X509_get_subject_name(param_1);
  iVar4 = X509_NAME_cmp(a_00,pXVar3);
  if (iVar4 == 0) {
    param_1->ex_flags = param_1->ex_flags | 0x20;
  }
  lVar5 = ASN1_INTEGER_get(param_1->cert_info->version);
  if (lVar5 == 0) {
    param_1->ex_flags = param_1->ex_flags | 0x40;
  }
  a_01 = (BASIC_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x57,(int *)0x0,(int *)0x0);
  if (a_01 != (BASIC_CONSTRAINTS *)0x0) {
    if (a_01->ca == 0) {
      if (a_01->pathlen == (ASN1_INTEGER *)0x0) {
LAB_081720fc:
        param_1->ex_pathlen = -1;
      }
      else {
        uVar20 = param_1->ex_flags;
LAB_08171c01:
        param_1->ex_pathlen = 0;
        param_1->ex_flags = uVar20 | 0x80;
      }
    }
    else {
      a = a_01->pathlen;
      uVar20 = param_1->ex_flags | 0x10;
      param_1->ex_flags = uVar20;
      if (a == (ASN1_INTEGER *)0x0) goto LAB_081720fc;
      if (a->type == 0x102) goto LAB_08171c01;
      lVar5 = ASN1_INTEGER_get(a);
      param_1->ex_pathlen = lVar5;
    }
    BASIC_CONSTRAINTS_free(a_01);
    param_1->ex_flags = param_1->ex_flags | 1;
  }
  a_02 = (PROXY_CERT_INFO_EXTENSION *)X509_get_ext_d2i(param_1,0x297,(int *)0x0,(int *)0x0);
  if (a_02 == (PROXY_CERT_INFO_EXTENSION *)0x0) goto LAB_08171c71;
  uVar6 = param_1->ex_flags;
  if ((uVar6 & 0x10) == 0) {
    iVar4 = X509_get_ext_by_NID(param_1,0x55,-1);
    if ((-1 < iVar4) || (iVar4 = X509_get_ext_by_NID(param_1,0x56,-1), -1 < iVar4)) {
      uVar6 = param_1->ex_flags;
      goto LAB_08171c40;
    }
  }
  else {
LAB_08171c40:
    param_1->ex_flags = uVar6 | 0x80;
  }
  if (a_02->pcPathLengthConstraint == (ASN1_INTEGER *)0x0) {
    param_1->ex_pcpathlen = -1;
  }
  else {
    lVar5 = ASN1_INTEGER_get(a_02->pcPathLengthConstraint);
    param_1->ex_pcpathlen = lVar5;
  }
  PROXY_CERT_INFO_EXTENSION_free(a_02);
  param_1->ex_flags = param_1->ex_flags | 0x400;
LAB_08171c71:
  pAVar7 = (ASN1_BIT_STRING *)X509_get_ext_d2i(param_1,0x53,(int *)0x0,(int *)0x0);
  if (pAVar7 != (ASN1_BIT_STRING *)0x0) {
    iVar4 = pAVar7->length;
    if (iVar4 < 1) {
      param_1->ex_kusage = 0;
    }
    else {
      pbVar2 = pAVar7->data;
      bVar1 = *pbVar2;
      param_1->ex_kusage = (uint)bVar1;
      if (iVar4 != 1) {
        param_1->ex_kusage = (uint)CONCAT11(pbVar2[1],bVar1);
      }
    }
    param_1->ex_flags = param_1->ex_flags | 2;
    ASN1_BIT_STRING_free(pAVar7);
  }
  param_1->ex_xkusage = 0;
  p_Var8 = (_STACK *)X509_get_ext_d2i(param_1,0x7e,(int *)0x0,(int *)0x0);
  if (p_Var8 != (_STACK *)0x0) {
    param_1->ex_flags = param_1->ex_flags | 4;
    local_28 = 0;
    while (iVar4 = sk_num(p_Var8), local_28 < iVar4) {
      pAVar9 = (ASN1_OBJECT *)sk_value(p_Var8,local_28);
      iVar4 = OBJ_obj2nid(pAVar9);
      if (iVar4 == 0x85) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x40;
      }
      else if (iVar4 < 0x86) {
        if (iVar4 == 0x82) {
          param_1->ex_xkusage = param_1->ex_xkusage | 2;
        }
        else if (iVar4 < 0x83) {
          if (iVar4 == 0x81) {
            param_1->ex_xkusage = param_1->ex_xkusage | 1;
          }
        }
        else if (iVar4 == 0x83) {
          param_1->ex_xkusage = param_1->ex_xkusage | 8;
        }
        else if (iVar4 == 0x84) {
          param_1->ex_xkusage = param_1->ex_xkusage | 4;
        }
      }
      else if (iVar4 == 0x8b) {
LAB_0817206b:
        param_1->ex_xkusage = param_1->ex_xkusage | 0x10;
      }
      else if (iVar4 < 0x8c) {
        if (iVar4 == 0x89) goto LAB_0817206b;
      }
      else if (iVar4 == 0xb4) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x20;
      }
      else if (iVar4 == 0x129) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x80;
      }
      local_28 = local_28 + 1;
    }
    sk_pop_free(p_Var8,ASN1_OBJECT_free);
  }
  pAVar7 = (ASN1_BIT_STRING *)X509_get_ext_d2i(param_1,0x47,(int *)0x0,(int *)0x0);
  if (pAVar7 != (ASN1_BIT_STRING *)0x0) {
    uVar20 = 0;
    if (0 < pAVar7->length) {
      uVar20 = (ulong)*pAVar7->data;
    }
    param_1->ex_flags = param_1->ex_flags | 8;
    param_1->ex_nscert = uVar20;
    ASN1_BIT_STRING_free(pAVar7);
  }
  pAVar10 = (ASN1_OCTET_STRING *)X509_get_ext_d2i(param_1,0x52,(int *)0x0,(int *)0x0);
  param_1->skid = pAVar10;
  pAVar11 = (AUTHORITY_KEYID *)X509_get_ext_d2i(param_1,0x5a,(int *)0x0,(int *)0x0);
  param_1->akid = pAVar11;
  psVar12 = (stack_st_GENERAL_NAME *)X509_get_ext_d2i(param_1,0x55,(int *)0x0,(int *)0x0);
  param_1->altname = psVar12;
  pNVar13 = (NAME_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x29a,&local_28,(int *)0x0);
  param_1->nc = pNVar13;
  if ((pNVar13 == (NAME_CONSTRAINTS *)0x0) && (local_28 != -1)) {
    param_1->ex_flags = param_1->ex_flags | 0x80;
  }
  p_Var8 = (_STACK *)X509_get_ext_d2i(param_1,0x67,(int *)0x0,(int *)0x0);
  param_1->crldp = (stack_st_DIST_POINT *)p_Var8;
  for (iVar4 = 0; iVar14 = sk_num(p_Var8), iVar4 < iVar14; iVar4 = iVar4 + 1) {
    ppDVar15 = (DIST_POINT_NAME **)sk_value((_STACK *)param_1->crldp,iVar4);
    pDVar16 = ppDVar15[1];
    if (pDVar16 == (DIST_POINT_NAME *)0x0) {
      ppDVar15[3] = (DIST_POINT_NAME *)0x807f;
    }
    else {
      iVar14 = pDVar16->type;
      if (iVar14 < 1) {
        pDVar16 = ppDVar15[3];
      }
      else {
        pXVar3 = pDVar16->dpname;
        bVar1 = *(byte *)&pXVar3->entries;
        pDVar16 = (DIST_POINT_NAME *)(uint)bVar1;
        ppDVar15[3] = pDVar16;
        if (iVar14 != 1) {
          pDVar16 = (DIST_POINT_NAME *)
                    (uint)CONCAT11(*(undefined *)((int)&pXVar3->entries + 1),bVar1);
        }
      }
      ppDVar15[3] = (DIST_POINT_NAME *)((uint)pDVar16 & 0x807f);
    }
    if ((*ppDVar15 != (DIST_POINT_NAME *)0x0) && (iVar14 = 0, (*ppDVar15)->type == 1)) {
      for (; iVar18 = sk_num((_STACK *)ppDVar15[2]), iVar14 < iVar18; iVar14 = iVar14 + 1) {
        piVar17 = (int *)sk_value((_STACK *)ppDVar15[2],iVar14);
        if (*piVar17 == 4) {
          pXVar3 = (X509_NAME *)piVar17[1];
          if (pXVar3 != (X509_NAME *)0x0) goto LAB_08171ef5;
          break;
        }
      }
      pXVar3 = X509_get_issuer_name(param_1);
LAB_08171ef5:
      DIST_POINT_set_dpname(*ppDVar15,pXVar3);
    }
    p_Var8 = (_STACK *)param_1->crldp;
  }
  local_28 = 0;
  do {
    iVar4 = X509_get_ext_count(param_1);
    if (iVar4 <= local_28) {
      uVar20 = param_1->ex_flags;
LAB_08171fc5:
      param_1->ex_flags = uVar20 | 0x100;
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    ex = X509_get_ext(param_1,local_28);
    pAVar9 = X509_EXTENSION_get_object(ex);
    iVar4 = OBJ_obj2nid(pAVar9);
    if (iVar4 == 0x359) {
      param_1->ex_flags = param_1->ex_flags | 0x1000;
    }
    iVar4 = X509_EXTENSION_get_critical(ex);
    if (iVar4 != 0) {
      pAVar9 = X509_EXTENSION_get_object(ex);
      local_24 = OBJ_obj2nid(pAVar9);
      if ((local_24 == 0) ||
         (pvVar19 = OBJ_bsearch_(&local_24,supported_nids_13619,0xb,4,nid_cmp_BSEARCH_CMP_FN),
         pvVar19 == (void *)0x0)) {
        uVar20 = param_1->ex_flags | 0x200;
        goto LAB_08171fc5;
      }
    }
    local_28 = local_28 + 1;
  } while( true );
}

