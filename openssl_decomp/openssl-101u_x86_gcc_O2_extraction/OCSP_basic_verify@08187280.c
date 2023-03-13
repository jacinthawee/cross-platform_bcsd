
int OCSP_basic_verify(OCSP_BASICRESP *bs,stack_st_X509 *certs,X509_STORE *st,ulong flags)

{
  OCSP_RESPID *pOVar1;
  BUF_MEM *pBVar2;
  _STACK *p_Var3;
  OCSP_CERTID *a;
  OCSP_CERTID *b;
  int iVar4;
  void *data;
  int iVar5;
  _STACK *p_Var6;
  EVP_PKEY *pkey;
  OCSP_CERTID **ppOVar7;
  char *pcVar8;
  X509 *pXVar9;
  EVP_MD *pEVar10;
  int iVar11;
  int in_GS_OFFSET;
  _STACK *local_d8;
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
        if (iVar4 == 0) goto LAB_081873b5;
      }
    }
LAB_08187330:
    if ((flags & 2) == 0) {
      p_Var6 = (_STACK *)bs->certs;
      if (pOVar1->type == 0) {
        pXVar9 = X509_find_by_subject((stack_st_X509 *)p_Var6,(pOVar1->value).byName);
LAB_0818780e:
        if (pXVar9 != (X509 *)0x0) {
          iVar11 = 1;
          goto LAB_081873d3;
        }
      }
      else if (((pOVar1->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
        pBVar2 = ((pOVar1->value).byName)->bytes;
        for (iVar11 = 0; iVar4 = sk_num(p_Var6), iVar11 < iVar4; iVar11 = iVar11 + 1) {
          pXVar9 = (X509 *)sk_value(p_Var6,iVar11);
          pEVar10 = EVP_sha1();
          X509_pubkey_digest(pXVar9,pEVar10,local_34,(uint *)0x0);
          iVar4 = memcmp(pBVar2,local_34,0x14);
          if (iVar4 == 0) goto LAB_0818780e;
        }
      }
    }
    iVar11 = 0;
    ERR_put_error(0x27,0x69,0x76,"ocsp_vfy.c",0x5c);
    local_d8 = (_STACK *)0x0;
    goto LAB_08187360;
  }
  pXVar9 = X509_find_by_subject(certs,(pOVar1->value).byName);
LAB_081873b5:
  if (pXVar9 == (X509 *)0x0) goto LAB_08187330;
  iVar11 = 2;
  if ((flags & 0x200) != 0) {
    flags = flags | 0x10;
    iVar11 = 2;
  }
LAB_081873d3:
  if ((flags & 4) == 0) {
    pkey = X509_get_pubkey(pXVar9);
    if (pkey != (EVP_PKEY *)0x0) {
      iVar11 = ASN1_item_verify((ASN1_ITEM *)OCSP_RESPDATA_it,bs->signatureAlgorithm,bs->signature,
                                bs->tbsResponseData,pkey);
      EVP_PKEY_free(pkey);
      if (0 < iVar11) goto LAB_081873e1;
    }
    ERR_put_error(0x27,0x69,0x75,"ocsp_vfy.c",0x69);
    local_d8 = (_STACK *)0x0;
    goto LAB_08187360;
  }
LAB_081873e1:
  local_d8 = (_STACK *)0x0;
  if ((flags & 0x10) != 0) goto LAB_08187360;
  if ((((flags & 8) == 0) && (local_d8 = (_STACK *)bs->certs, local_d8 != (_STACK *)0x0)) &&
     (certs != (stack_st_X509 *)0x0)) {
    local_d8 = sk_dup(local_d8);
    for (iVar4 = 0; iVar5 = sk_num(&certs->stack), iVar4 < iVar5; iVar4 = iVar4 + 1) {
      data = sk_value(&certs->stack,iVar4);
      iVar5 = sk_push(local_d8,data);
      if (iVar5 == 0) {
        ERR_put_error(0x27,0x69,0x41,"ocsp_vfy.c",0x75);
        goto LAB_08187360;
      }
    }
  }
  iVar11 = X509_STORE_CTX_init(&local_bc,st,pXVar9,(stack_st_X509 *)local_d8);
  if (iVar11 == 0) {
    iVar11 = -1;
    ERR_put_error(0x27,0x69,0xb,"ocsp_vfy.c",0x7f);
    goto LAB_08187360;
  }
  X509_STORE_CTX_set_purpose(&local_bc,8);
  iVar11 = X509_verify_cert(&local_bc);
  p_Var6 = (_STACK *)X509_STORE_CTX_get1_chain(&local_bc);
  X509_STORE_CTX_cleanup(&local_bc);
  if (iVar11 < 1) {
    iVar4 = X509_STORE_CTX_get_error(&local_bc);
    ERR_put_error(0x27,0x69,0x65,"ocsp_vfy.c",0x8a);
    pcVar8 = X509_verify_cert_error_string(iVar4);
    ERR_add_error_data(2,"Verify error:",pcVar8);
  }
  else if ((flags & 0x100) == 0) {
    p_Var3 = (_STACK *)bs->tbsResponseData->responses;
    iVar11 = sk_num(p_Var6);
    if (iVar11 < 1) {
      iVar11 = -1;
      ERR_put_error(0x27,0x6c,0x69,"ocsp_vfy.c",0xed);
    }
    else {
      iVar11 = sk_num(p_Var3);
      if (iVar11 < 1) {
        iVar11 = -1;
        ERR_put_error(0x27,0x6b,0x6f,"ocsp_vfy.c",0x11a);
      }
      else {
        ppOVar7 = (OCSP_CERTID **)sk_value(p_Var3,0);
        a = *ppOVar7;
        if (iVar11 != 1) {
          iVar4 = 1;
          do {
            ppOVar7 = (OCSP_CERTID **)sk_value(p_Var3,iVar4);
            b = *ppOVar7;
            iVar5 = OCSP_id_issuer_cmp(a,b);
            if (iVar5 != 0) {
              iVar11 = OBJ_cmp(b->hashAlgorithm->algorithm,a->hashAlgorithm->algorithm);
              if (iVar11 == 0) goto LAB_08187685;
              break;
            }
            iVar4 = iVar4 + 1;
          } while (iVar11 != iVar4);
        }
        pXVar9 = (X509 *)sk_value(p_Var6,0);
        iVar11 = sk_num(p_Var6);
        if (iVar11 < 2) {
LAB_0818766c:
          iVar11 = ocsp_match_issuerid();
          if (iVar11 == 0) {
LAB_08187685:
            iVar11 = 0;
            if ((flags & 0x20) == 0) {
              iVar4 = sk_num(p_Var6);
              pXVar9 = (X509 *)sk_value(p_Var6,iVar4 + -1);
              iVar4 = X509_check_trust(pXVar9,0xb4,0);
              if (iVar4 == 1) goto LAB_081874c2;
              ERR_put_error(0x27,0x69,0x70,"ocsp_vfy.c",0xa6);
            }
          }
        }
        else {
          sk_value(p_Var6,1);
          iVar11 = ocsp_match_issuerid();
          if (-1 < iVar11) {
            if (iVar11 == 0) goto LAB_0818766c;
            X509_check_purpose(pXVar9,-1,0);
            if (((*(byte *)&pXVar9->ex_flags & 4) != 0) &&
               ((*(byte *)&pXVar9->ex_xkusage & 0x20) != 0)) goto LAB_081874c2;
            ERR_put_error(0x27,0x6a,0x67,"ocsp_vfy.c",0x168);
            goto LAB_08187685;
          }
        }
      }
    }
  }
  else {
LAB_081874c2:
    iVar11 = 1;
  }
  if (p_Var6 != (_STACK *)0x0) {
    sk_pop_free(p_Var6,X509_free);
  }
LAB_08187360:
  if ((bs->certs != (stack_st_X509 *)0x0) && (certs != (stack_st_X509 *)0x0)) {
    sk_free(local_d8);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar11;
}

