
int OCSP_basic_verify(OCSP_BASICRESP *bs,stack_st_X509 *certs,X509_STORE *st,ulong flags)

{
  OCSP_RESPID *pOVar1;
  BUF_MEM *pBVar2;
  _STACK *p_Var3;
  OCSP_CERTID *a;
  OCSP_CERTID *b;
  int iVar4;
  _STACK *p_Var5;
  EVP_PKEY *pkey;
  OCSP_CERTID **ppOVar6;
  int iVar7;
  char *pcVar8;
  X509 *pXVar9;
  EVP_MD *pEVar10;
  int iVar11;
  int in_GS_OFFSET;
  stack_st_X509 *chain;
  X509_STORE_CTX local_bc;
  uchar local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pOVar1 = bs->tbsResponseData->responderId;
  if (pOVar1->type != 0) {
    if (((pOVar1->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
      pBVar2 = ((pOVar1->value).byName)->bytes;
      for (iVar11 = 0; iVar4 = sk_num(&certs->stack), iVar11 < iVar4; iVar11 = iVar11 + 1) {
        pXVar9 = (X509 *)sk_value(&certs->stack,iVar11);
        pEVar10 = EVP_sha1();
        X509_pubkey_digest(pXVar9,pEVar10,local_34,(uint *)0x0);
        iVar4 = memcmp(pBVar2,local_34,0x14);
        if (iVar4 == 0) goto LAB_08188e65;
      }
    }
LAB_08188dfc:
    if ((flags & 2) == 0) {
      p_Var5 = (_STACK *)bs->certs;
      if (pOVar1->type == 0) {
        pXVar9 = X509_find_by_subject((stack_st_X509 *)p_Var5,(pOVar1->value).byName);
LAB_081891e8:
        if (pXVar9 != (X509 *)0x0) {
          iVar11 = 1;
          goto LAB_08188e7f;
        }
      }
      else if (((pOVar1->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
        pBVar2 = ((pOVar1->value).byName)->bytes;
        for (iVar11 = 0; iVar4 = sk_num(p_Var5), iVar11 < iVar4; iVar11 = iVar11 + 1) {
          pXVar9 = (X509 *)sk_value(p_Var5,iVar11);
          pEVar10 = EVP_sha1();
          X509_pubkey_digest(pXVar9,pEVar10,local_34,(uint *)0x0);
          iVar4 = memcmp(pBVar2,local_34,0x14);
          if (iVar4 == 0) goto LAB_081891e8;
        }
      }
    }
    iVar11 = 0;
    ERR_put_error(0x27,0x69,0x76,"ocsp_vfy.c",0x55);
    goto LAB_08188e28;
  }
  pXVar9 = X509_find_by_subject(certs,(pOVar1->value).byName);
LAB_08188e65:
  if (pXVar9 == (X509 *)0x0) goto LAB_08188dfc;
  iVar11 = 2;
  if ((flags & 0x200) != 0) {
    flags = flags | 0x10;
    iVar11 = 2;
  }
LAB_08188e7f:
  if ((flags & 4) == 0) {
    pkey = X509_get_pubkey(pXVar9);
    if (pkey != (EVP_PKEY *)0x0) {
      iVar11 = ASN1_item_verify((ASN1_ITEM *)OCSP_RESPDATA_it,bs->signatureAlgorithm,bs->signature,
                                bs->tbsResponseData,pkey);
      EVP_PKEY_free(pkey);
      if (0 < iVar11) goto LAB_08188e8d;
    }
    ERR_put_error(0x27,0x69,0x75,"ocsp_vfy.c",0x65);
    goto LAB_08188e28;
  }
LAB_08188e8d:
  if ((flags & 0x10) != 0) goto LAB_08188e28;
  if ((flags & 8) == 0) {
    chain = bs->certs;
  }
  else {
    chain = (stack_st_X509 *)0x0;
  }
  iVar11 = X509_STORE_CTX_init(&local_bc,st,pXVar9,chain);
  if (iVar11 == 0) {
    iVar11 = -1;
    ERR_put_error(0x27,0x69,0xb,"ocsp_vfy.c",0x73);
    goto LAB_08188e28;
  }
  X509_STORE_CTX_set_purpose(&local_bc,8);
  iVar11 = X509_verify_cert(&local_bc);
  p_Var5 = (_STACK *)X509_STORE_CTX_get1_chain(&local_bc);
  X509_STORE_CTX_cleanup(&local_bc);
  if (iVar11 < 1) {
    iVar4 = X509_STORE_CTX_get_error(&local_bc);
    ERR_put_error(0x27,0x69,0x65,"ocsp_vfy.c",0x7e);
    pcVar8 = X509_verify_cert_error_string(iVar4);
    ERR_add_error_data(2,"Verify error:",pcVar8);
  }
  else if ((flags & 0x100) == 0) {
    p_Var3 = (_STACK *)bs->tbsResponseData->responses;
    iVar11 = sk_num(p_Var5);
    if (iVar11 < 1) {
      iVar11 = -1;
      ERR_put_error(0x27,0x6c,0x69,"ocsp_vfy.c",0xe2);
    }
    else {
      iVar11 = sk_num(p_Var3);
      if (iVar11 < 1) {
        iVar11 = -1;
        ERR_put_error(0x27,0x6b,0x6f,"ocsp_vfy.c",0x10d);
      }
      else {
        ppOVar6 = (OCSP_CERTID **)sk_value(p_Var3,0);
        a = *ppOVar6;
        if (iVar11 != 1) {
          iVar4 = 1;
          do {
            ppOVar6 = (OCSP_CERTID **)sk_value(p_Var3,iVar4);
            b = *ppOVar6;
            iVar7 = OCSP_id_issuer_cmp(a,b);
            if (iVar7 != 0) {
              iVar11 = OBJ_cmp(b->hashAlgorithm->algorithm,a->hashAlgorithm->algorithm);
              if (iVar11 == 0) goto LAB_081890bd;
              break;
            }
            iVar4 = iVar4 + 1;
          } while (iVar11 != iVar4);
        }
        pXVar9 = (X509 *)sk_value(p_Var5,0);
        iVar11 = sk_num(p_Var5);
        if (iVar11 < 2) {
LAB_081890a6:
          iVar11 = ocsp_match_issuerid();
          if (iVar11 == 0) {
LAB_081890bd:
            iVar11 = 0;
            if ((flags & 0x20) == 0) {
              iVar4 = sk_num(p_Var5);
              pXVar9 = (X509 *)sk_value(p_Var5,iVar4 + -1);
              iVar4 = X509_check_trust(pXVar9,0xb4,0);
              if (iVar4 == 1) goto LAB_08188f09;
              ERR_put_error(0x27,0x69,0x70,"ocsp_vfy.c",0x98);
            }
          }
        }
        else {
          sk_value(p_Var5,1);
          iVar11 = ocsp_match_issuerid();
          if (-1 < iVar11) {
            if (iVar11 == 0) goto LAB_081890a6;
            X509_check_purpose(pXVar9,-1,0);
            if (((*(byte *)&pXVar9->ex_flags & 4) != 0) &&
               ((*(byte *)&pXVar9->ex_xkusage & 0x20) != 0)) goto LAB_08188f09;
            ERR_put_error(0x27,0x6a,0x67,"ocsp_vfy.c",0x162);
            goto LAB_081890bd;
          }
        }
      }
    }
  }
  else {
LAB_08188f09:
    iVar11 = 1;
  }
  if (p_Var5 != (_STACK *)0x0) {
    sk_pop_free(p_Var5,X509_free);
  }
LAB_08188e28:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar11;
}

