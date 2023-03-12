
PKCS12 * PKCS12_create(char *pass,char *name,EVP_PKEY *pkey,X509 *cert,stack_st_X509 *ca,int nid_key
                      ,int nid_cert,int iter,int mac_iter,int keytype)

{
  bool bVar1;
  PKCS12_SAFEBAG *pPVar2;
  int iVar3;
  uchar *puVar4;
  EVP_PKEY *pEVar5;
  PKCS7 *pPVar6;
  EVP_MD *type;
  X509_ATTRIBUTE *pXVar7;
  stack_st_X509_ATTRIBUTE *psVar8;
  EVP_PKEY *pEVar9;
  X509 *pXVar10;
  int iVar11;
  EVP_PKEY *pEVar12;
  EVP_PKEY *local_7c;
  uint local_78;
  int local_74;
  int local_70;
  uchar auStack_6c [64];
  int local_2c;
  
  if (nid_cert == 0) {
    nid_cert = 0x95;
  }
  if (nid_key == 0) {
    nid_key = 0x92;
  }
  if (mac_iter == 0) {
    mac_iter = 1;
  }
  if (iter == 0) {
    iter = 0x800;
  }
  local_2c = __stack_chk_guard;
  local_7c = (EVP_PKEY *)0x0;
  local_78 = 0;
  if ((pkey == (EVP_PKEY *)0x0 && cert == (X509 *)0x0) && (ca == (stack_st_X509 *)0x0)) {
    ERR_put_error(0x23,0x69,0x68,"p12_crt.c",0x71);
    goto LAB_000dd8c0;
  }
  pEVar12 = pkey;
  if (pkey != (EVP_PKEY *)0x0) {
    pEVar12 = (EVP_PKEY *)0x1;
  }
  pXVar10 = cert;
  if (cert != (X509 *)0x0) {
    pXVar10 = (X509 *)0x1;
  }
  if (((uint)pEVar12 & (uint)pXVar10) == 0) {
    if (pXVar10 == (X509 *)0x0) {
LAB_000dd846:
      iVar11 = 0;
      iVar3 = sk_num(&ca->stack);
      if (0 < iVar3) {
        do {
          pXVar10 = (X509 *)sk_value(&ca->stack,iVar11);
          local_74 = -1;
          local_70 = -1;
          pPVar2 = PKCS12_x5092certbag(pXVar10);
          if (pPVar2 == (PKCS12_SAFEBAG *)0x0) goto LAB_000dd8ae;
          puVar4 = X509_alias_get0(pXVar10,&local_74);
          if (((puVar4 != (uchar *)0x0) &&
              (iVar3 = PKCS12_add_friendlyname_asc(pPVar2,(char *)puVar4,local_74), iVar3 == 0)) ||
             ((puVar4 = X509_keyid_get0(pXVar10,&local_70), puVar4 != (uchar *)0x0 &&
              (iVar3 = PKCS12_add_localkeyid(pPVar2,puVar4,local_70), iVar3 == 0)))) {
LAB_000dd8a8:
            PKCS12_SAFEBAG_free(pPVar2);
            goto LAB_000dd8ae;
          }
          if (local_7c == (EVP_PKEY *)0x0) {
            local_7c = (EVP_PKEY *)sk_new_null();
            if (local_7c != (EVP_PKEY *)0x0) {
              pEVar9 = (EVP_PKEY *)sk_push((_STACK *)local_7c,pPVar2);
              if (pEVar9 != (EVP_PKEY *)0x0) goto LAB_000dd8e6;
              sk_free((_STACK *)local_7c);
              local_7c = pEVar9;
            }
            goto LAB_000dd8a8;
          }
          iVar3 = sk_push((_STACK *)local_7c,pPVar2);
          if (iVar3 == 0) goto LAB_000dd8a8;
LAB_000dd8e6:
          iVar11 = iVar11 + 1;
          iVar3 = sk_num(&ca->stack);
        } while (iVar11 < iVar3);
      }
      pEVar9 = local_7c;
      pEVar5 = local_7c;
      if (local_7c == (EVP_PKEY *)0x0) {
LAB_000dd98a:
        sk_pop_free((_STACK *)local_7c,PKCS12_SAFEBAG_free);
        local_7c = (EVP_PKEY *)0x0;
        if (pEVar12 == (EVP_PKEY *)0x0) goto LAB_000dda62;
        pPVar2 = PKCS12_add_key((stack_st_PKCS12_SAFEBAG **)&local_7c,pkey,keytype,iter,nid_key,pass
                               );
        if (pPVar2 != (PKCS12_SAFEBAG *)0x0) {
          iVar3 = EVP_PKEY_get_attr_by_NID(pkey,0x1a1,-1);
          if (-1 < iVar3) {
            pXVar7 = EVP_PKEY_get_attr(pkey,iVar3);
            psVar8 = X509at_add1_attr(&pPVar2->attrib,pXVar7);
            if (psVar8 == (stack_st_X509_ATTRIBUTE *)0x0) goto LAB_000dda4a;
          }
          iVar3 = EVP_PKEY_get_attr_by_NID(pkey,0x358,-1);
          if (-1 < iVar3) {
            pXVar7 = EVP_PKEY_get_attr(pkey,iVar3);
            psVar8 = X509at_add1_attr(&pPVar2->attrib,pXVar7);
            if (psVar8 == (stack_st_X509_ATTRIBUTE *)0x0) goto LAB_000dda4a;
          }
          if (((name == (char *)0x0) ||
              (iVar3 = PKCS12_add_friendlyname_asc(pPVar2,name,-1), iVar3 != 0)) &&
             ((local_78 == 0 ||
              (iVar3 = PKCS12_add_localkeyid(pPVar2,auStack_6c,local_78), iVar3 != 0)))) {
            pEVar12 = local_7c;
            if (local_7c != (EVP_PKEY *)0x0) {
              bVar1 = false;
              pEVar9 = pEVar5;
              if (pEVar5 == (EVP_PKEY *)0x0) {
                pEVar9 = (EVP_PKEY *)sk_new_null();
                if (pEVar9 == (EVP_PKEY *)0x0) goto LAB_000dd8ae;
                bVar1 = true;
              }
              pPVar6 = PKCS12_pack_p7data((stack_st_PKCS12_SAFEBAG *)pEVar12);
              pEVar5 = pEVar9;
              if ((pPVar6 == (PKCS7 *)0x0) ||
                 (iVar3 = sk_push((_STACK *)pEVar9,pPVar6), pEVar12 = local_7c, iVar3 == 0)) {
                if (bVar1) {
                  pEVar5 = (EVP_PKEY *)0x0;
                  sk_free((_STACK *)pEVar9);
                }
                if (pPVar6 != (PKCS7 *)0x0) {
                  PKCS7_free(pPVar6);
                }
                goto LAB_000dda4a;
              }
            }
LAB_000dda62:
            sk_pop_free((_STACK *)pEVar12,PKCS12_SAFEBAG_free);
            local_7c = (EVP_PKEY *)0x0;
            ca = (stack_st_X509 *)PKCS12_init(0x15);
            if ((PKCS12 *)ca != (PKCS12 *)0x0) {
              iVar3 = PKCS12_pack_authsafes((PKCS12 *)ca,(stack_st_PKCS7 *)pEVar5);
              if (iVar3 != 0) {
                sk_pop_free((_STACK *)pEVar5,PKCS7_free);
                if ((mac_iter == -1) ||
                   (iVar3 = PKCS12_set_mac((PKCS12 *)ca,pass,-1,(uchar *)0x0,0,mac_iter,
                                           (EVP_MD *)0x0), iVar3 != 0)) goto LAB_000dd8c0;
                PKCS12_free((PKCS12 *)ca);
                goto LAB_000dd8ae;
              }
              PKCS12_free((PKCS12 *)ca);
            }
          }
        }
LAB_000dda4a:
        if (pEVar5 != (EVP_PKEY *)0x0) {
          sk_pop_free((_STACK *)pEVar5,PKCS7_free);
        }
      }
      else {
        pEVar5 = (EVP_PKEY *)sk_new_null();
        if (pEVar5 != (EVP_PKEY *)0x0) {
          if (nid_cert == -1) {
            pPVar6 = PKCS12_pack_p7data((stack_st_PKCS12_SAFEBAG *)pEVar9);
          }
          else {
            pPVar6 = PKCS12_pack_p7encdata
                               (nid_cert,pass,-1,(uchar *)0x0,0,iter,
                                (stack_st_PKCS12_SAFEBAG *)pEVar9);
          }
          if (pPVar6 == (PKCS7 *)0x0) {
            sk_free((_STACK *)pEVar5);
          }
          else {
            iVar3 = sk_push((_STACK *)pEVar5,pPVar6);
            if (iVar3 != 0) goto LAB_000dd98a;
            sk_free((_STACK *)pEVar5);
            PKCS7_free(pPVar6);
          }
        }
      }
    }
    else {
LAB_000dd826:
      pPVar2 = PKCS12_add_cert((stack_st_PKCS12_SAFEBAG **)&local_7c,cert);
      if (((name == (char *)0x0) ||
          (iVar3 = PKCS12_add_friendlyname_asc(pPVar2,name,-1), iVar3 != 0)) &&
         ((local_78 == 0 || (iVar3 = PKCS12_add_localkeyid(pPVar2,auStack_6c,local_78), iVar3 != 0))
         )) goto LAB_000dd846;
    }
LAB_000dd8ae:
    if (local_7c != (EVP_PKEY *)0x0) {
      sk_pop_free((_STACK *)local_7c,PKCS12_SAFEBAG_free);
    }
  }
  else {
    iVar3 = X509_check_private_key(cert,pkey);
    if (iVar3 != 0) {
      type = EVP_sha1();
      X509_digest(cert,type,auStack_6c,&local_78);
      goto LAB_000dd826;
    }
  }
  ca = (stack_st_X509 *)0x0;
LAB_000dd8c0:
  if (local_2c == __stack_chk_guard) {
    return (PKCS12 *)ca;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

