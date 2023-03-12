
uint crl_cb(int param_1,X509_CRL **param_2)

{
  byte bVar1;
  X509_CRL *data;
  int iVar2;
  ASN1_BIT_STRING *pAVar3;
  byte *pbVar4;
  _STACK *p_Var5;
  ASN1_OBJECT *pAVar6;
  undefined *puVar7;
  uint uVar8;
  EVP_MD *type;
  ISSUING_DIST_POINT *pIVar9;
  AUTHORITY_KEYID *pAVar10;
  ASN1_INTEGER *pAVar11;
  ASN1_OBJECT **ppAVar12;
  X509_REVOKED *x;
  stack_st_GENERAL_NAME *data_00;
  ASN1_ENUMERATED *a;
  long lVar13;
  _STACK *p_Var14;
  int iVar15;
  uint uVar16;
  int iVar17;
  stack_st_GENERAL_NAME *psVar18;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  puVar7 = default_crl_method;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  data = *param_2;
  if (param_1 == 3) {
    if ((*(code **)(data->meth + 8) == (code *)0x0) ||
       (uVar8 = (**(code **)(data->meth + 8))(data), uVar8 != 0)) {
      if (data->akid != (AUTHORITY_KEYID *)0x0) {
        AUTHORITY_KEYID_free(data->akid);
      }
      if (data->idp != (ISSUING_DIST_POINT *)0x0) {
        ISSUING_DIST_POINT_free(data->idp);
      }
      ASN1_INTEGER_free(data->crl_number);
      ASN1_INTEGER_free(data->base_crl_number);
      sk_pop_free((_STACK *)data->issuers,GENERAL_NAMES_free);
      uVar8 = 1;
    }
    goto LAB_081424d6;
  }
  if (param_1 == 5) {
    type = EVP_sha1();
    X509_CRL_digest(data,type,data->sha1_hash,(uint *)0x0);
    pIVar9 = (ISSUING_DIST_POINT *)X509_CRL_get_ext_d2i(data,0x302,(int *)0x0,(int *)0x0);
    data->idp = pIVar9;
    if (pIVar9 != (ISSUING_DIST_POINT *)0x0) {
      uVar8 = data->idp_flags;
      iVar17 = pIVar9->onlyuser;
      uVar16 = uVar8 | 1;
      data->idp_flags = uVar16;
      if (iVar17 < 1) {
        iVar17 = 2;
        iVar15 = 1;
      }
      else {
        uVar16 = uVar8 | 5;
        iVar17 = 3;
        data->idp_flags = uVar16;
        iVar15 = 2;
      }
      if (pIVar9->onlyCA < 1) {
        iVar17 = iVar15;
        if (0 < pIVar9->onlyattr) goto LAB_081425b1;
      }
      else {
        iVar2 = pIVar9->onlyattr;
        uVar16 = uVar16 | 8;
        data->idp_flags = uVar16;
        if (0 < iVar2) {
LAB_081425b1:
          uVar16 = uVar16 | 0x10;
          data->idp_flags = uVar16;
          iVar15 = iVar17;
        }
        if (iVar15 != 1) {
          uVar16 = uVar16 | 2;
          data->idp_flags = uVar16;
        }
      }
      if (0 < pIVar9->indirectCRL) {
        uVar16 = uVar16 | 0x20;
        data->idp_flags = uVar16;
      }
      pAVar3 = pIVar9->onlysomereasons;
      if (pAVar3 != (ASN1_BIT_STRING *)0x0) {
        iVar17 = pAVar3->length;
        data->idp_flags = uVar16 | 0x40;
        if (iVar17 < 1) {
          uVar8 = data->idp_reasons;
        }
        else {
          pbVar4 = pAVar3->data;
          bVar1 = *pbVar4;
          uVar8 = (uint)bVar1;
          data->idp_reasons = uVar8;
          if (iVar17 != 1) {
            uVar8 = (uint)CONCAT11(pbVar4[1],bVar1);
          }
        }
        data->idp_reasons = uVar8 & 0x807f;
      }
      DIST_POINT_set_dpname(pIVar9->distpoint,data->crl->issuer);
    }
    pAVar10 = (AUTHORITY_KEYID *)X509_CRL_get_ext_d2i(data,0x5a,(int *)0x0,(int *)0x0);
    data->akid = pAVar10;
    pAVar11 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(data,0x58,(int *)0x0,(int *)0x0);
    data->crl_number = pAVar11;
    pAVar11 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(data,0x8c,(int *)0x0,(int *)0x0);
    data->base_crl_number = pAVar11;
    if ((pAVar11 != (ASN1_INTEGER *)0x0) && (data->crl_number == (ASN1_INTEGER *)0x0)) {
      data->flags = data->flags | 0x80;
    }
    p_Var5 = (_STACK *)data->crl->extensions;
    for (iVar17 = 0; iVar15 = sk_num(p_Var5), iVar17 < iVar15; iVar17 = iVar17 + 1) {
      ppAVar12 = (ASN1_OBJECT **)sk_value(p_Var5,iVar17);
      iVar15 = OBJ_obj2nid(*ppAVar12);
      if (iVar15 == 0x359) {
        pAVar6 = ppAVar12[1];
        data->flags = data->flags | 0x1000;
      }
      else {
        pAVar6 = ppAVar12[1];
      }
      if (0 < (int)pAVar6) {
        if ((iVar15 != 0x302) && (iVar15 != 0x8c)) {
          data->flags = data->flags | 0x200;
        }
        break;
      }
    }
    psVar18 = (stack_st_GENERAL_NAME *)0x0;
    p_Var5 = (_STACK *)data->crl->revoked;
    for (iVar17 = 0; iVar15 = sk_num(p_Var5), iVar17 < iVar15; iVar17 = iVar17 + 1) {
      x = (X509_REVOKED *)sk_value(p_Var5,iVar17);
      data_00 = (stack_st_GENERAL_NAME *)X509_REVOKED_get_ext_d2i(x,0x303,&local_24,(int *)0x0);
      if (data_00 != (stack_st_GENERAL_NAME *)0x0) {
        p_Var14 = (_STACK *)data->issuers;
        if (p_Var14 == (_STACK *)0x0) {
          p_Var14 = sk_new_null();
          data->issuers = (stack_st_GENERAL_NAMES *)p_Var14;
          if (p_Var14 != (_STACK *)0x0) goto LAB_0814275c;
        }
        else {
LAB_0814275c:
          iVar15 = sk_push(p_Var14,data_00);
          psVar18 = data_00;
          if (iVar15 != 0) goto LAB_08142771;
        }
        uVar8 = 0;
        goto LAB_081424d6;
      }
      if (local_24 != -1) {
LAB_0814290c:
        data->flags = data->flags | 0x80;
        break;
      }
LAB_08142771:
      x->issuer = psVar18;
      a = (ASN1_ENUMERATED *)X509_REVOKED_get_ext_d2i(x,0x8d,&local_24,(int *)0x0);
      if (a == (ASN1_ENUMERATED *)0x0) {
        if (local_24 != -1) goto LAB_0814290c;
        x->reason = -1;
      }
      else {
        lVar13 = ASN1_ENUMERATED_get(a);
        x->reason = lVar13;
        ASN1_ENUMERATED_free(a);
      }
      p_Var14 = (_STACK *)x->extensions;
      local_24 = 0;
      while (iVar15 = sk_num(p_Var14), local_24 < iVar15) {
        ppAVar12 = (ASN1_OBJECT **)sk_value(p_Var14,local_24);
        if ((0 < (int)ppAVar12[1]) && (iVar15 = OBJ_obj2nid(*ppAVar12), iVar15 != 0x303)) {
          data->flags = data->flags | 0x200;
          break;
        }
        local_24 = local_24 + 1;
      }
    }
    if (*(code **)(data->meth + 4) != (code *)0x0) {
      iVar17 = (**(code **)(data->meth + 4))(data);
      uVar8 = (uint)(iVar17 != 0);
      goto LAB_081424d6;
    }
  }
  else if (param_1 == 1) {
    data->idp = (ISSUING_DIST_POINT *)0x0;
    data->akid = (AUTHORITY_KEYID *)0x0;
    data->flags = 0;
    data->idp_flags = 0;
    data->idp_reasons = 0x807f;
    data->meth = (X509_CRL_METHOD *)puVar7;
    data->meth_data = (void *)0x0;
    uVar8 = 1;
    data->issuers = (stack_st_GENERAL_NAMES *)0x0;
    data->crl_number = (ASN1_INTEGER *)0x0;
    data->base_crl_number = (ASN1_INTEGER *)0x0;
    goto LAB_081424d6;
  }
  uVar8 = 1;
LAB_081424d6:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

