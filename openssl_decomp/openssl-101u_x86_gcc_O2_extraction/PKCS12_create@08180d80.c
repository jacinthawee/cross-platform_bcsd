
PKCS12 * PKCS12_create(char *pass,char *name,EVP_PKEY *pkey,X509 *cert,stack_st_X509 *ca,int nid_key
                      ,int nid_cert,int iter,int mac_iter,int keytype)

{
  _STACK *sk;
  int key_nid;
  int iter_00;
  int iter_01;
  PKCS12_SAFEBAG *pPVar1;
  int iVar2;
  X509 *x509;
  uchar *puVar3;
  PKCS12 *p12;
  _STACK *st;
  PKCS7 *pPVar4;
  int iVar5;
  EVP_MD *type;
  X509_ATTRIBUTE *pXVar6;
  stack_st_X509_ATTRIBUTE *psVar7;
  _STACK *p_Var8;
  int iVar9;
  int in_GS_OFFSET;
  _STACK *local_70;
  uint local_6c;
  int local_68;
  int local_64;
  uchar local_60 [64];
  int local_20;
  
  local_70 = (_STACK *)0x0;
  local_6c = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = 0x95;
  if (nid_cert != 0) {
    iVar5 = nid_cert;
  }
  key_nid = 0x92;
  if (nid_key != 0) {
    key_nid = nid_key;
  }
  iter_00 = 0x800;
  if (iter != 0) {
    iter_00 = iter;
  }
  iter_01 = 1;
  if (mac_iter != 0) {
    iter_01 = mac_iter;
  }
  if ((ca == (stack_st_X509 *)0x0 && cert == (X509 *)0x0) && (pkey == (EVP_PKEY *)0x0)) {
    ERR_put_error(0x23,0x69,0x68,"p12_crt.c",0x71);
    p12 = (PKCS12 *)0x0;
    goto LAB_08180f97;
  }
  if ((pkey == (EVP_PKEY *)0x0) || (cert == (X509 *)0x0)) {
    if (cert != (X509 *)0x0) goto LAB_08180e72;
LAB_08180eb3:
    iVar9 = 0;
    iVar2 = sk_num(&ca->stack);
    if (0 < iVar2) {
      do {
        x509 = (X509 *)sk_value(&ca->stack,iVar9);
        local_68 = -1;
        local_64 = -1;
        pPVar1 = PKCS12_x5092certbag(x509);
        if (pPVar1 == (PKCS12_SAFEBAG *)0x0) goto LAB_08180f7c;
        puVar3 = X509_alias_get0(x509,&local_68);
        if (((puVar3 != (uchar *)0x0) &&
            (iVar2 = PKCS12_add_friendlyname_asc(pPVar1,(char *)puVar3,local_68), iVar2 == 0)) ||
           ((puVar3 = X509_keyid_get0(x509,&local_64), puVar3 != (uchar *)0x0 &&
            (iVar2 = PKCS12_add_localkeyid(pPVar1,puVar3,local_64), iVar2 == 0)))) {
LAB_08180f70:
          PKCS12_SAFEBAG_free(pPVar1);
          goto LAB_08180f7c;
        }
        if (local_70 == (_STACK *)0x0) {
          local_70 = sk_new_null();
          if (local_70 != (_STACK *)0x0) {
            iVar2 = sk_push(local_70,pPVar1);
            if (iVar2 != 0) goto LAB_08180fd8;
            sk_free(local_70);
            local_70 = (_STACK *)0x0;
          }
          goto LAB_08180f70;
        }
        iVar2 = sk_push(local_70,pPVar1);
        if (iVar2 == 0) goto LAB_08180f70;
LAB_08180fd8:
        iVar9 = iVar9 + 1;
        iVar2 = sk_num(&ca->stack);
      } while (iVar9 < iVar2);
    }
    p_Var8 = local_70;
    if (local_70 == (_STACK *)0x0) {
      st = (_STACK *)0x0;
LAB_08181124:
      sk_pop_free(local_70,PKCS12_SAFEBAG_free);
      local_70 = (_STACK *)0x0;
      p_Var8 = st;
      if (pkey == (EVP_PKEY *)0x0) {
LAB_0818129f:
        sk_pop_free(local_70,PKCS12_SAFEBAG_free);
        local_70 = (_STACK *)0x0;
        p12 = PKCS12_init(0x15);
        st = p_Var8;
        if (p12 != (PKCS12 *)0x0) {
          iVar5 = PKCS12_pack_authsafes(p12,(stack_st_PKCS7 *)p_Var8);
          if (iVar5 != 0) {
            sk_pop_free(p_Var8,PKCS7_free);
            if ((iter_01 == -1) ||
               (iVar5 = PKCS12_set_mac(p12,pass,-1,(uchar *)0x0,0,iter_01,(EVP_MD *)0x0), iVar5 != 0
               )) goto LAB_08180f97;
            PKCS12_free(p12);
            goto LAB_08180f7c;
          }
          PKCS12_free(p12);
        }
      }
      else {
        pPVar1 = PKCS12_add_key((stack_st_PKCS12_SAFEBAG **)&local_70,pkey,keytype,iter_00,key_nid,
                                pass);
        if (pPVar1 != (PKCS12_SAFEBAG *)0x0) {
          iVar5 = EVP_PKEY_get_attr_by_NID(pkey,0x1a1,-1);
          if (-1 < iVar5) {
            pXVar6 = EVP_PKEY_get_attr(pkey,iVar5);
            psVar7 = X509at_add1_attr(&pPVar1->attrib,pXVar6);
            if (psVar7 == (stack_st_X509_ATTRIBUTE *)0x0) goto LAB_0818127f;
          }
          iVar5 = EVP_PKEY_get_attr_by_NID(pkey,0x358,-1);
          if (-1 < iVar5) {
            pXVar6 = EVP_PKEY_get_attr(pkey,iVar5);
            psVar7 = X509at_add1_attr(&pPVar1->attrib,pXVar6);
            if (psVar7 == (stack_st_X509_ATTRIBUTE *)0x0) goto LAB_0818127f;
          }
          if (((name == (char *)0x0) ||
              (iVar5 = PKCS12_add_friendlyname_asc(pPVar1,name,-1), iVar5 != 0)) &&
             ((local_6c == 0 ||
              (iVar5 = PKCS12_add_localkeyid(pPVar1,local_60,local_6c), iVar5 != 0)))) {
            sk = local_70;
            if (local_70 == (_STACK *)0x0) goto LAB_0818129f;
            if (st == (_STACK *)0x0) {
              p_Var8 = sk_new_null();
              if (p_Var8 != (_STACK *)0x0) {
                pPVar4 = PKCS12_pack_p7data((stack_st_PKCS12_SAFEBAG *)sk);
                if (pPVar4 != (PKCS7 *)0x0) {
                  iVar5 = sk_push(p_Var8,pPVar4);
                  if (iVar5 == 0) {
                    sk_free(p_Var8);
                    goto LAB_08181273;
                  }
                  goto LAB_0818129f;
                }
                sk_free(p_Var8);
              }
              goto LAB_08180f7c;
            }
            pPVar4 = PKCS12_pack_p7data((stack_st_PKCS12_SAFEBAG *)local_70);
            if (pPVar4 != (PKCS7 *)0x0) {
              iVar5 = sk_push(st,pPVar4);
              if (iVar5 != 0) goto LAB_0818129f;
LAB_08181273:
              PKCS7_free(pPVar4);
            }
          }
        }
      }
LAB_0818127f:
      if (st != (_STACK *)0x0) {
        sk_pop_free(st,PKCS7_free);
      }
    }
    else {
      st = sk_new_null();
      if (st != (_STACK *)0x0) {
        if (iVar5 == -1) {
          pPVar4 = PKCS12_pack_p7data((stack_st_PKCS12_SAFEBAG *)p_Var8);
        }
        else {
          pPVar4 = PKCS12_pack_p7encdata
                             (iVar5,pass,-1,(uchar *)0x0,0,iter_00,(stack_st_PKCS12_SAFEBAG *)p_Var8
                             );
        }
        if (pPVar4 == (PKCS7 *)0x0) {
          sk_free(st);
        }
        else {
          iVar5 = sk_push(st,pPVar4);
          if (iVar5 != 0) goto LAB_08181124;
          sk_free(st);
          PKCS7_free(pPVar4);
        }
      }
    }
LAB_08180f7c:
    if (local_70 != (_STACK *)0x0) {
      sk_pop_free(local_70,PKCS12_SAFEBAG_free);
    }
  }
  else {
    iVar2 = X509_check_private_key(cert,pkey);
    if (iVar2 != 0) {
      type = EVP_sha1();
      X509_digest(cert,type,local_60,&local_6c);
LAB_08180e72:
      pPVar1 = PKCS12_add_cert((stack_st_PKCS12_SAFEBAG **)&local_70,cert);
      if (((name == (char *)0x0) ||
          (iVar2 = PKCS12_add_friendlyname_asc(pPVar1,name,-1), iVar2 != 0)) &&
         ((local_6c == 0 || (iVar2 = PKCS12_add_localkeyid(pPVar1,local_60,local_6c), iVar2 != 0))))
      goto LAB_08180eb3;
      goto LAB_08180f7c;
    }
  }
  p12 = (PKCS12 *)0x0;
LAB_08180f97:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return p12;
}

