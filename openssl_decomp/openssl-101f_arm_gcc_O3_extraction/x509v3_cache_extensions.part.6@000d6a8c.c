
void x509v3_cache_extensions_part_6(X509 *param_1)

{
  byte bVar1;
  EVP_MD *type;
  X509_NAME *pXVar2;
  X509_NAME *b;
  int iVar3;
  long lVar4;
  BASIC_CONSTRAINTS *a;
  ASN1_INTEGER *a_00;
  PROXY_CERT_INFO_EXTENSION *a_01;
  ASN1_BIT_STRING *pAVar5;
  _STACK *p_Var6;
  ASN1_OBJECT *pAVar7;
  ASN1_OCTET_STRING *pAVar8;
  AUTHORITY_KEYID *pAVar9;
  stack_st_GENERAL_NAME *psVar10;
  NAME_CONSTRAINTS *pNVar11;
  int iVar12;
  DIST_POINT_NAME **ppDVar13;
  int *piVar14;
  int iVar15;
  X509_EXTENSION *ex;
  void *pvVar16;
  byte *pbVar17;
  ulong uVar18;
  uint uVar19;
  DIST_POINT_NAME *pDVar20;
  bool bVar21;
  ulong local_20;
  int local_1c;
  
  type = EVP_sha1();
  X509_digest(param_1,type,(uchar *)&param_1->rfc3779_addr,(uint *)0x0);
  pXVar2 = X509_get_subject_name(param_1);
  b = X509_get_issuer_name(param_1);
  iVar3 = X509_NAME_cmp(pXVar2,b);
  if (iVar3 == 0) {
    param_1->ex_flags = param_1->ex_flags | 0x20;
  }
  lVar4 = ASN1_INTEGER_get(param_1->cert_info->version);
  if (lVar4 == 0) {
    param_1->ex_flags = param_1->ex_flags | 0x40;
  }
  a = (BASIC_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x57,(int *)0x0,(int *)0x0);
  if (a != (BASIC_CONSTRAINTS *)0x0) {
    iVar3 = a->ca;
    if (iVar3 == 0) {
      a_00 = a->pathlen;
      if (a_00 != (ASN1_INTEGER *)0x0) goto LAB_000d6af8;
LAB_000d6e16:
      param_1->ex_pathlen = -1;
    }
    else {
      a_00 = a->pathlen;
      param_1->ex_flags = param_1->ex_flags | 0x10;
      if (a_00 == (ASN1_INTEGER *)0x0) goto LAB_000d6e16;
LAB_000d6af8:
      if ((a_00->type == 0x102) || (iVar3 == 0)) {
        param_1->ex_pathlen = 0;
        param_1->ex_flags = param_1->ex_flags | 0x80;
      }
      else {
        lVar4 = ASN1_INTEGER_get(a_00);
        param_1->ex_pathlen = lVar4;
      }
    }
    BASIC_CONSTRAINTS_free(a);
    param_1->ex_flags = param_1->ex_flags | 1;
  }
  a_01 = (PROXY_CERT_INFO_EXTENSION *)X509_get_ext_d2i(param_1,0x297,(int *)0x0,(int *)0x0);
  if (a_01 == (PROXY_CERT_INFO_EXTENSION *)0x0) goto LAB_000d6b5e;
  uVar19 = param_1->ex_flags;
  if ((uVar19 & 0x10) == 0) {
    iVar3 = X509_get_ext_by_NID(param_1,0x55,0);
    if ((-1 < iVar3) || (iVar3 = X509_get_ext_by_NID(param_1,0x56,0), -1 < iVar3)) {
      uVar19 = param_1->ex_flags;
      goto LAB_000d6b3c;
    }
  }
  else {
LAB_000d6b3c:
    param_1->ex_flags = uVar19 | 0x80;
  }
  if (a_01->pcPathLengthConstraint == (ASN1_INTEGER *)0x0) {
    param_1->ex_pcpathlen = -1;
  }
  else {
    lVar4 = ASN1_INTEGER_get(a_01->pcPathLengthConstraint);
    param_1->ex_pcpathlen = lVar4;
  }
  PROXY_CERT_INFO_EXTENSION_free(a_01);
  param_1->ex_flags = param_1->ex_flags | 0x400;
LAB_000d6b5e:
  pAVar5 = (ASN1_BIT_STRING *)X509_get_ext_d2i(param_1,0x53,(int *)0x0,(int *)0x0);
  if (pAVar5 != (ASN1_BIT_STRING *)0x0) {
    iVar3 = pAVar5->length;
    if (iVar3 < 1) {
      param_1->ex_kusage = 0;
    }
    else {
      pbVar17 = pAVar5->data;
      bVar1 = *pbVar17;
      param_1->ex_kusage = (uint)bVar1;
      if (iVar3 != 1) {
        param_1->ex_kusage = (uint)CONCAT11(pbVar17[1],bVar1);
      }
    }
    param_1->ex_flags = param_1->ex_flags | 2;
    ASN1_BIT_STRING_free(pAVar5);
  }
  param_1->ex_xkusage = 0;
  p_Var6 = (_STACK *)X509_get_ext_d2i(param_1,0x7e,(int *)0x0,(int *)0x0);
  if (p_Var6 != (_STACK *)0x0) {
    local_20 = 0;
    param_1->ex_flags = param_1->ex_flags | 4;
    while (iVar3 = sk_num(p_Var6), (int)local_20 < iVar3) {
      pAVar7 = (ASN1_OBJECT *)sk_value(p_Var6,local_20);
      iVar3 = OBJ_obj2nid(pAVar7);
      if (iVar3 == 0x85) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x40;
      }
      else if (iVar3 < 0x86) {
        if (iVar3 == 0x82) {
          param_1->ex_xkusage = param_1->ex_xkusage | 2;
        }
        else if (iVar3 < 0x83) {
          if (iVar3 == 0x81) {
            param_1->ex_xkusage = param_1->ex_xkusage | 1;
          }
        }
        else if (iVar3 == 0x83) {
          param_1->ex_xkusage = param_1->ex_xkusage | 8;
        }
        else if (iVar3 == 0x84) {
          param_1->ex_xkusage = param_1->ex_xkusage | 4;
        }
      }
      else if (iVar3 == 0x8b) {
LAB_000d6dee:
        param_1->ex_xkusage = param_1->ex_xkusage | 0x10;
      }
      else if (iVar3 < 0x8c) {
        if (iVar3 == 0x89) goto LAB_000d6dee;
      }
      else if (iVar3 == 0xb4) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x20;
      }
      else if (iVar3 == 0x129) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x80;
      }
      local_20 = local_20 + 1;
    }
    sk_pop_free(p_Var6,ASN1_OBJECT_free + 1);
  }
  pAVar5 = (ASN1_BIT_STRING *)X509_get_ext_d2i(param_1,0x47,(int *)0x0,(int *)0x0);
  if (pAVar5 != (ASN1_BIT_STRING *)0x0) {
    if (pAVar5->length < 1) {
      uVar18 = 0;
    }
    else {
      uVar18 = (ulong)*pAVar5->data;
    }
    param_1->ex_nscert = uVar18;
    param_1->ex_flags = param_1->ex_flags | 8;
    ASN1_BIT_STRING_free(pAVar5);
  }
  pAVar8 = (ASN1_OCTET_STRING *)X509_get_ext_d2i(param_1,0x52,(int *)0x0,(int *)0x0);
  param_1->skid = pAVar8;
  pAVar9 = (AUTHORITY_KEYID *)X509_get_ext_d2i(param_1,0x5a,(int *)0x0,(int *)0x0);
  param_1->akid = pAVar9;
  psVar10 = (stack_st_GENERAL_NAME *)X509_get_ext_d2i(param_1,0x55,(int *)0x0,(int *)0x0);
  param_1->altname = psVar10;
  pNVar11 = (NAME_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x29a,(int *)&local_20,(int *)0x0);
  param_1->nc = pNVar11;
  if (pNVar11 == (NAME_CONSTRAINTS *)0x0) {
    uVar18 = local_20 + 1;
    bVar21 = uVar18 != 0;
    if (bVar21) {
      uVar18 = param_1->ex_flags | 0x80;
    }
    if (bVar21) {
      param_1->ex_flags = uVar18;
    }
  }
  p_Var6 = (_STACK *)X509_get_ext_d2i(param_1,0x67,(int *)0x0,(int *)0x0);
  iVar3 = 0;
  param_1->crldp = (stack_st_DIST_POINT *)p_Var6;
  do {
    iVar12 = sk_num(p_Var6);
    if (iVar12 <= iVar3) {
      local_20 = 0;
      do {
        iVar3 = X509_get_ext_count(param_1);
        if (iVar3 <= (int)local_20) {
          param_1->ex_flags = param_1->ex_flags | 0x100;
          return;
        }
        uVar18 = local_20;
        ex = X509_get_ext(param_1,local_20);
        pAVar7 = X509_EXTENSION_get_object(ex);
        iVar3 = OBJ_obj2nid(pAVar7);
        if (iVar3 == 0x359) {
          uVar18 = param_1->ex_flags | 0x1000;
        }
        if (iVar3 == 0x359) {
          param_1->ex_flags = uVar18;
        }
        iVar3 = X509_EXTENSION_get_critical(ex);
        if (iVar3 != 0) {
          pAVar7 = X509_EXTENSION_get_object(ex);
          local_1c = OBJ_obj2nid(pAVar7);
          if ((local_1c == 0) ||
             (pvVar16 = OBJ_bsearch_(&local_1c,&supported_nids_16260,0xb,4,
                                     nid_cmp_BSEARCH_CMP_FN + 1), pvVar16 == (void *)0x0)) {
            param_1->ex_flags = param_1->ex_flags | 0x300;
            return;
          }
        }
        local_20 = local_20 + 1;
      } while( true );
    }
    ppDVar13 = (DIST_POINT_NAME **)sk_value((_STACK *)param_1->crldp,iVar3);
    pDVar20 = ppDVar13[1];
    if (pDVar20 == (DIST_POINT_NAME *)0x0) {
      ppDVar13[3] = (DIST_POINT_NAME *)0x807f;
    }
    else {
      uVar19 = pDVar20->type;
      if ((int)uVar19 < 1) {
        pDVar20 = ppDVar13[3];
      }
      else {
        pXVar2 = pDVar20->dpname;
        bVar21 = uVar19 != 1;
        pDVar20 = (DIST_POINT_NAME *)(uint)*(byte *)&pXVar2->entries;
        ppDVar13[3] = pDVar20;
        if (bVar21) {
          uVar19 = (uint)*(byte *)((int)&pXVar2->entries + 1);
        }
        if (bVar21) {
          pDVar20 = (DIST_POINT_NAME *)((uint)pDVar20 | uVar19 << 8);
        }
      }
      ppDVar13[3] = (DIST_POINT_NAME *)((uint)pDVar20 & 0x807f);
    }
    if ((*ppDVar13 != (DIST_POINT_NAME *)0x0) && ((*ppDVar13)->type == 1)) {
      iVar12 = 0;
      do {
        iVar15 = sk_num((_STACK *)ppDVar13[2]);
        if (iVar15 <= iVar12) goto LAB_000d6d1c;
        piVar14 = (int *)sk_value((_STACK *)ppDVar13[2],iVar12);
        iVar12 = iVar12 + 1;
      } while (*piVar14 != 4);
      pXVar2 = (X509_NAME *)piVar14[1];
      if (pXVar2 == (X509_NAME *)0x0) {
LAB_000d6d1c:
        pXVar2 = X509_get_issuer_name(param_1);
      }
      DIST_POINT_set_dpname(*ppDVar13,pXVar2);
    }
    p_Var6 = (_STACK *)param_1->crldp;
    iVar3 = iVar3 + 1;
  } while( true );
}

