
/* WARNING: Removing unreachable block (ram,0x005aa560) */

int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                       EVP_CIPHER *cipher,EVP_MD *md_type,int en_de)

{
  undefined *puVar1;
  ASN1_STRING *pAVar2;
  int **ppiVar3;
  EVP_CIPHER *pEVar4;
  X509 *bag;
  X509 *name;
  int iVar5;
  PKCS8_PRIV_KEY_INFO *p8;
  PKCS12_SAFEBAG *a;
  ASN1_OBJECT *pAVar6;
  int *piVar7;
  X509_ALGOR *pXVar8;
  X509 *x509;
  X509 *pXVar9;
  X509_CINF *usage;
  char *iter;
  uchar *unaff_s2;
  stack_st_void *unaff_s3;
  uchar *salt;
  int saltlen;
  char *pcStack_ec;
  X509_CINF *pXStack_e4;
  X509_CINF *pXStack_e0;
  X509_ALGOR *pXStack_dc;
  undefined *puStack_d4;
  EVP_CIPHER *pEStack_d0;
  uchar *puStack_cc;
  stack_st_void *psStack_c8;
  int iStack_c4;
  EVP_CIPHER *local_8c;
  uchar *local_80;
  uchar auStack_7c [16];
  uchar auStack_6c [64];
  int *local_2c;
  
  puStack_d4 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar2 = (param->value).asn1_string, unaff_s3 = (stack_st_void *)passlen,
     pAVar2 == (ASN1_STRING *)0x0)) {
LAB_005a9fec:
    iter = "p12_crpt.c";
    usage = (X509_CINF *)&DAT_00000065;
    x509 = (X509 *)&DAT_00000078;
    (*(code *)PTR_ERR_put_error_006a9030)(0x23);
    local_8c = (EVP_CIPHER *)0x0;
    pass = (char *)unaff_s2;
    passlen = (int)unaff_s3;
  }
  else {
    local_80 = pAVar2->data;
    ppiVar3 = (int **)(*(code *)PTR_d2i_PBEPARAM_006a8318)(0,&local_80,pAVar2->length);
    unaff_s2 = (uchar *)pass;
    if (ppiVar3 == (int **)0x0) goto LAB_005a9fec;
    if (ppiVar3[1] == (int *)0x0) {
      local_8c = (EVP_CIPHER *)0x1;
    }
    else {
      local_8c = (EVP_CIPHER *)(*(code *)PTR_ASN1_INTEGER_get_006a831c)();
    }
    salt = (uchar *)(*ppiVar3)[2];
    saltlen = **ppiVar3;
    iVar5 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(cipher);
    pEVar4 = (EVP_CIPHER *)
             PKCS12_key_gen_asc(pass,passlen,salt,saltlen,1,(int)local_8c,iVar5,auStack_6c,md_type);
    if (pEVar4 == (EVP_CIPHER *)0x0) {
      usage = (X509_CINF *)&DAT_0000006b;
      local_8c = pEVar4;
LAB_005aa1ec:
      iter = "p12_crpt.c";
      x509 = (X509 *)&DAT_00000078;
      (*(code *)PTR_ERR_put_error_006a9030)(0x23);
      (*(code *)PTR_PBEPARAM_free_006a8320)(ppiVar3);
    }
    else {
      iVar5 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(cipher);
      local_8c = (EVP_CIPHER *)
                 PKCS12_key_gen_asc(pass,passlen,salt,saltlen,2,(int)local_8c,iVar5,auStack_7c,
                                    md_type);
      if (local_8c == (EVP_CIPHER *)0x0) {
        usage = (X509_CINF *)&DAT_0000006a;
        goto LAB_005aa1ec;
      }
      (*(code *)PTR_PBEPARAM_free_006a8320)(ppiVar3);
      usage = (X509_CINF *)0x0;
      iter = (char *)auStack_6c;
      local_8c = (EVP_CIPHER *)(*(code *)PTR_EVP_CipherInit_ex_006a864c)(ctx,cipher);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_6c,0x40);
      x509 = (X509 *)&SUB_00000010;
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_7c);
      cipher = local_8c;
      pass = (char *)auStack_7c;
    }
  }
  if (local_2c == *(int **)puStack_d4) {
    return (int)local_8c;
  }
  iStack_c4 = 0x5aa258;
  piVar7 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pXStack_e4 = (X509_CINF *)0xffffffff;
  pXStack_e0 = (X509_CINF *)0xffffffff;
  pXStack_dc = *(X509_ALGOR **)PTR___stack_chk_guard_006aabf0;
  name = x509;
  pEStack_d0 = cipher;
  puStack_cc = (uchar *)pass;
  psStack_c8 = (stack_st_void *)passlen;
  bag = (X509 *)PKCS12_x5092certbag(x509);
  if (bag == (X509 *)0x0) {
    bag = (X509 *)0x0;
    goto LAB_005aa308;
  }
  name = (X509 *)(*(code *)PTR_X509_alias_get0_006a87fc)(x509,&pXStack_e4);
  if ((name == (X509 *)0x0) ||
     (usage = pXStack_e4,
     iVar5 = PKCS12_add_friendlyname_asc((PKCS12_SAFEBAG *)bag,(char *)name,(int)pXStack_e4),
     iVar5 != 0)) {
    pXVar9 = (X509 *)&pXStack_e0;
    name = (X509 *)(*(code *)PTR_X509_keyid_get0_006aa314)(x509,pXVar9);
    if ((name == (X509 *)0x0) ||
       (usage = pXStack_e0,
       iVar5 = PKCS12_add_localkeyid((PKCS12_SAFEBAG *)bag,(uchar *)name,(int)pXStack_e0),
       pXVar9 = name, iVar5 != 0)) {
      name = pXVar9;
      if (piVar7 == (int *)0x0) goto LAB_005aa308;
      if (*piVar7 == 0) {
        iVar5 = (*(code *)PTR_sk_new_null_006a80a4)();
        *piVar7 = iVar5;
        if (iVar5 != 0) {
          name = bag;
          iVar5 = (*(code *)PTR_sk_push_006a80a8)(iVar5,bag);
          if (iVar5 != 0) goto LAB_005aa308;
          (*(code *)PTR_sk_free_006a7f80)(*piVar7);
          *piVar7 = 0;
        }
      }
      else {
        name = bag;
        iVar5 = (*(code *)PTR_sk_push_006a80a8)(*piVar7,bag);
        if (iVar5 != 0) goto LAB_005aa308;
      }
    }
  }
  PKCS12_SAFEBAG_free((PKCS12_SAFEBAG *)bag);
  bag = (X509 *)0x0;
LAB_005aa308:
  if (pXStack_dc == *(X509_ALGOR **)puVar1) {
    return (int)bag;
  }
  pXVar8 = pXStack_dc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  p8 = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_EVP_PKEY2PKCS8_006a9fb8)(name);
  if ((p8 != (PKCS8_PRIV_KEY_INFO *)0x0) &&
     ((usage == (X509_CINF *)0x0 || (iVar5 = PKCS8_add_keyusage(p8,(int)usage), iVar5 != 0)))) {
    a = PKCS12_MAKE_SHKEYBAG((int)&_gp,pcStack_ec,-1,(uchar *)0x0,0,(int)iter,p8);
    (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a8340)(p8);
    if (a != (PKCS12_SAFEBAG *)0x0) {
      if (pXVar8 == (X509_ALGOR *)0x0) {
        return (int)a;
      }
      if (pXVar8->algorithm == (ASN1_OBJECT *)0x0) {
        pAVar6 = (ASN1_OBJECT *)(*(code *)PTR_sk_new_null_006a80a4)();
        pXVar8->algorithm = pAVar6;
        if (pAVar6 != (ASN1_OBJECT *)0x0) {
          iVar5 = (*(code *)PTR_sk_push_006a80a8)(pAVar6,a);
          if (iVar5 != 0) {
            return (int)a;
          }
          (*(code *)PTR_sk_free_006a7f80)(pXVar8->algorithm);
          pXVar8->algorithm = (ASN1_OBJECT *)0x0;
        }
      }
      else {
        iVar5 = (*(code *)PTR_sk_push_006a80a8)(pXVar8->algorithm,a);
        if (iVar5 != 0) {
          return (int)a;
        }
      }
      PKCS12_SAFEBAG_free(a);
      return 0;
    }
  }
  return 0;
}

