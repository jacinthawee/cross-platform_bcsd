
int crl_cb(int param_1,X509_CRL **param_2)

{
  undefined *puVar1;
  int iVar2;
  EVP_MD *type;
  ISSUING_DIST_POINT *pIVar3;
  AUTHORITY_KEYID *pAVar4;
  ASN1_INTEGER *pAVar5;
  X509_REVOKED *x;
  stack_st_GENERAL_NAME *data;
  _STACK *p_Var6;
  ASN1_ENUMERATED *a;
  long lVar7;
  ASN1_OBJECT **ppAVar8;
  int iVar9;
  uint uVar10;
  ASN1_BIT_STRING *pAVar11;
  byte *pbVar12;
  uint uVar13;
  X509_CRL_INFO *pXVar14;
  uint unaff_r4;
  X509_CRL *data_00;
  _STACK *p_Var15;
  stack_st_GENERAL_NAME *psVar16;
  int local_2c [2];
  
  puVar1 = default_crl_method;
  data_00 = *param_2;
  if (param_1 == 3) {
    if ((*(code **)(data_00->meth + 8) == (code *)0x0) ||
       (iVar2 = (**(code **)(data_00->meth + 8))(data_00), iVar2 != 0)) {
      if (data_00->akid != (AUTHORITY_KEYID *)0x0) {
        AUTHORITY_KEYID_free(data_00->akid);
      }
      if (data_00->idp != (ISSUING_DIST_POINT *)0x0) {
        ISSUING_DIST_POINT_free(data_00->idp);
      }
      ASN1_INTEGER_free(data_00->crl_number);
      ASN1_INTEGER_free(data_00->base_crl_number);
      sk_pop_free((_STACK *)data_00->issuers,GENERAL_NAMES_free + 1);
      return 1;
    }
  }
  else {
    if (param_1 == 5) {
      type = EVP_sha1();
      X509_CRL_digest(data_00,type,data_00->sha1_hash,(uint *)0x0);
      pIVar3 = (ISSUING_DIST_POINT *)X509_CRL_get_ext_d2i(data_00,0x302,(int *)0x0,(int *)0x0);
      data_00->idp = pIVar3;
      if (pIVar3 != (ISSUING_DIST_POINT *)0x0) {
        iVar2 = pIVar3->onlyuser;
        uVar10 = data_00->idp_flags;
        iVar9 = pIVar3->onlyCA;
        uVar13 = uVar10 | 1;
        data_00->idp_flags = uVar13;
        if (iVar2 < 1) {
          uVar10 = 1;
          unaff_r4 = 0;
        }
        else {
          uVar13 = uVar10 | 5;
        }
        if (0 < iVar2) {
          data_00->idp_flags = uVar13;
          uVar10 = 2;
          unaff_r4 = 1;
        }
        iVar2 = pIVar3->onlyattr;
        if (0 < iVar9) {
          uVar13 = uVar13 | 8;
        }
        if (0 < iVar9) {
          data_00->idp_flags = uVar13;
          unaff_r4 = uVar10;
        }
        if (0 < iVar2) {
          unaff_r4 = unaff_r4 + 1;
          uVar13 = uVar13 | 0x10;
        }
        if (0 < iVar2) {
          data_00->idp_flags = uVar13;
        }
        iVar2 = pIVar3->indirectCRL;
        if (1 < (int)unaff_r4) {
          uVar13 = uVar13 | 2;
        }
        if (1 < (int)unaff_r4) {
          data_00->idp_flags = uVar13;
        }
        pAVar11 = pIVar3->onlysomereasons;
        if (0 < iVar2) {
          uVar13 = uVar13 | 0x20;
        }
        if (0 < iVar2) {
          data_00->idp_flags = uVar13;
        }
        if (pAVar11 != (ASN1_BIT_STRING *)0x0) {
          iVar2 = pAVar11->length;
          data_00->idp_flags = uVar13 | 0x40;
          if (iVar2 < 1) {
            uVar10 = data_00->idp_reasons;
          }
          else {
            pbVar12 = pAVar11->data;
            uVar10 = (uint)*pbVar12;
            data_00->idp_reasons = uVar10;
            if (iVar2 != 1) {
              pbVar12 = (byte *)(uint)pbVar12[1];
            }
            if (iVar2 != 1) {
              uVar10 = uVar10 | (int)pbVar12 << 8;
            }
          }
          data_00->idp_reasons = uVar10 & 0x807f;
        }
        DIST_POINT_set_dpname(pIVar3->distpoint,data_00->crl->issuer);
      }
      pAVar4 = (AUTHORITY_KEYID *)X509_CRL_get_ext_d2i(data_00,0x5a,(int *)0x0,(int *)0x0);
      data_00->akid = pAVar4;
      pAVar5 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(data_00,0x58,(int *)0x0,(int *)0x0);
      data_00->crl_number = pAVar5;
      pAVar5 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(data_00,0x8c,(int *)0x0,(int *)0x0);
      data_00->base_crl_number = pAVar5;
      if ((pAVar5 != (ASN1_INTEGER *)0x0) && (data_00->crl_number == (ASN1_INTEGER *)0x0)) {
        data_00->flags = data_00->flags | 0x80;
      }
      pXVar14 = data_00->crl;
      p_Var15 = (_STACK *)pXVar14->extensions;
      iVar2 = 0;
      do {
        iVar9 = sk_num(p_Var15);
        if (iVar9 <= iVar2) goto LAB_000b593e;
        ppAVar8 = (ASN1_OBJECT **)sk_value(p_Var15,iVar2);
        iVar9 = OBJ_obj2nid(*ppAVar8);
        if (iVar9 == 0x359) {
          pXVar14 = (X509_CRL_INFO *)(data_00->flags | 0x1000);
        }
        if (iVar9 == 0x359) {
          data_00->flags = (int)pXVar14;
        }
        pXVar14 = (X509_CRL_INFO *)ppAVar8[1];
        iVar2 = iVar2 + 1;
      } while ((int)pXVar14 < 1);
      if ((iVar9 != 0x5a && iVar9 != 0x302) && (iVar9 != 0x8c)) {
        data_00->flags = data_00->flags | 0x200;
      }
LAB_000b593e:
      psVar16 = (stack_st_GENERAL_NAME *)0x0;
      p_Var15 = (_STACK *)data_00->crl->revoked;
      for (iVar2 = 0; iVar9 = sk_num(p_Var15), iVar2 < iVar9; iVar2 = iVar2 + 1) {
        x = (X509_REVOKED *)sk_value(p_Var15,iVar2);
        data = (stack_st_GENERAL_NAME *)X509_REVOKED_get_ext_d2i(x,0x303,local_2c,(int *)0x0);
        if (data == (stack_st_GENERAL_NAME *)0x0) {
          if (local_2c[0] == -1) goto LAB_000b599c;
LAB_000b5a4a:
          data_00->flags = data_00->flags | 0x80;
          break;
        }
        p_Var6 = (_STACK *)data_00->issuers;
        if (p_Var6 == (_STACK *)0x0) {
          p_Var6 = sk_new_null();
          data_00->issuers = (stack_st_GENERAL_NAMES *)p_Var6;
          if (p_Var6 == (_STACK *)0x0) {
            return 0;
          }
        }
        iVar9 = sk_push(p_Var6,data);
        psVar16 = data;
        if (iVar9 == 0) {
          return 0;
        }
LAB_000b599c:
        x->issuer = psVar16;
        a = (ASN1_ENUMERATED *)X509_REVOKED_get_ext_d2i(x,0x8d,local_2c,(int *)0x0);
        if (a == (ASN1_ENUMERATED *)0x0) {
          if (local_2c[0] != -1) goto LAB_000b5a4a;
          x->reason = -1;
        }
        else {
          lVar7 = ASN1_ENUMERATED_get(a);
          x->reason = lVar7;
          ASN1_ENUMERATED_free(a);
        }
        p_Var6 = (_STACK *)x->extensions;
        local_2c[0] = 0;
        while (iVar9 = sk_num(p_Var6), local_2c[0] < iVar9) {
          ppAVar8 = (ASN1_OBJECT **)sk_value(p_Var6,local_2c[0]);
          if ((0 < (int)ppAVar8[1]) && (iVar9 = OBJ_obj2nid(*ppAVar8), iVar9 != 0x303)) {
            data_00->flags = data_00->flags | 0x200;
            break;
          }
          local_2c[0] = local_2c[0] + 1;
        }
      }
      if (*(code **)(data_00->meth + 4) != (code *)0x0) {
        iVar2 = (**(code **)(data_00->meth + 4))(data_00);
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        return iVar2;
      }
    }
    else if (param_1 == 1) {
      data_00->idp = (ISSUING_DIST_POINT *)0x0;
      data_00->akid = (AUTHORITY_KEYID *)0x0;
      data_00->meth = (X509_CRL_METHOD *)puVar1;
      data_00->flags = 0;
      data_00->idp_flags = 0;
      data_00->meth_data = (void *)0x0;
      data_00->issuers = (stack_st_GENERAL_NAMES *)0x0;
      data_00->crl_number = (ASN1_INTEGER *)0x0;
      data_00->base_crl_number = (ASN1_INTEGER *)0x0;
      data_00->idp_reasons = 0x807f;
      return 1;
    }
    iVar2 = 1;
  }
  return iVar2;
}

