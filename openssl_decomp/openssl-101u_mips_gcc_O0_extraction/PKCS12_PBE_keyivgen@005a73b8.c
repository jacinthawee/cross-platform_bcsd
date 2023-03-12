
/* WARNING: Removing unreachable block (ram,0x005a79a0) */

int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                       EVP_CIPHER *cipher,EVP_MD *md_type,int en_de)

{
  undefined *puVar1;
  ASN1_STRING *pAVar2;
  int **ppiVar3;
  ASIdentifiers_st *pAVar4;
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
  char *pcVar10;
  ASIdentifiers_st *unaff_s1;
  uchar *unaff_s2;
  uchar *salt;
  int saltlen;
  char *pcStack_ec;
  X509_CINF *pXStack_e4;
  X509_CINF *pXStack_e0;
  X509_ALGOR *pXStack_dc;
  undefined *puStack_d4;
  ASIdentifiers_st *pAStack_d0;
  uchar *puStack_cc;
  EVP_MD *pEStack_c8;
  code *pcStack_c4;
  ASIdentifiers_st *local_8c;
  uchar *local_80;
  uchar auStack_7c [16];
  ASN1_TYPE aAStack_6c [8];
  int *local_2c;
  
  puStack_d4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  local_8c = (ASIdentifiers_st *)0x0;
  x509 = (X509 *)pass;
  usage = (X509_CINF *)passlen;
  pAStack_d0 = unaff_s1;
  puStack_cc = unaff_s2;
  if (cipher != (EVP_CIPHER *)0x0) {
    if (((param != (ASN1_TYPE *)0x0) && (param->type == 0x10)) &&
       (pAVar2 = (param->value).asn1_string, unaff_s2 = (uchar *)passlen,
       pAVar2 != (ASN1_STRING *)0x0)) {
      local_80 = pAVar2->data;
      ppiVar3 = (int **)(*(code *)PTR_d2i_PBEPARAM_006a7204)(0,&local_80,pAVar2->length);
      unaff_s1 = (ASIdentifiers_st *)pass;
      if (ppiVar3 != (int **)0x0) {
        if (ppiVar3[1] == (int *)0x0) {
          local_8c = (ASIdentifiers_st *)0x1;
        }
        else {
          local_8c = (ASIdentifiers_st *)(*(code *)PTR_ASN1_INTEGER_get_006a7208)();
        }
        salt = (uchar *)(*ppiVar3)[2];
        saltlen = **ppiVar3;
        iVar5 = (*(code *)PTR_EVP_CIPHER_key_length_006a7554)(cipher);
        pAVar4 = (ASIdentifiers_st *)
                 PKCS12_key_gen_asc(pass,passlen,salt,saltlen,1,(int)local_8c,iVar5,
                                    (uchar *)aAStack_6c,md_type);
        if (pAVar4 == (ASIdentifiers_st *)0x0) {
          usage = (X509_CINF *)&DAT_0000006b;
          local_8c = pAVar4;
        }
        else {
          iVar5 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(cipher);
          local_8c = (ASIdentifiers_st *)
                     PKCS12_key_gen_asc(pass,passlen,salt,saltlen,2,(int)local_8c,iVar5,auStack_7c,
                                        md_type);
          if (local_8c != (ASIdentifiers_st *)0x0) {
            (*(code *)PTR_PBEPARAM_free_006a720c)(ppiVar3);
            usage = (X509_CINF *)0x0;
            param = aAStack_6c;
            local_8c = (ASIdentifiers_st *)(*(code *)PTR_EVP_CipherInit_ex_006a7560)(ctx,cipher);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(aAStack_6c,0x40);
            x509 = (X509 *)&SUB_00000010;
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_7c);
            pAStack_d0 = local_8c;
            puStack_cc = auStack_7c;
            goto LAB_005a7450;
          }
          usage = (X509_CINF *)&DAT_0000006a;
        }
        pcVar10 = "p12_crpt.c";
        x509 = (X509 *)&DAT_00000078;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x23);
        (*(code *)PTR_PBEPARAM_free_006a720c)(ppiVar3);
        param = (ASN1_TYPE *)pcVar10;
        pAStack_d0 = (ASIdentifiers_st *)pass;
        puStack_cc = (uchar *)passlen;
        goto LAB_005a7450;
      }
    }
    pcVar10 = "p12_crpt.c";
    usage = (X509_CINF *)&DAT_00000065;
    x509 = (X509 *)&DAT_00000078;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23);
    local_8c = (ASIdentifiers_st *)0x0;
    param = (ASN1_TYPE *)pcVar10;
    pAStack_d0 = unaff_s1;
    puStack_cc = unaff_s2;
  }
LAB_005a7450:
  if (local_2c == *(int **)puStack_d4) {
    return (int)local_8c;
  }
  pcStack_c4 = PKCS12_add_cert;
  piVar7 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pEStack_c8 = md_type;
  pXStack_e4 = (X509_CINF *)0xffffffff;
  pXStack_e0 = (X509_CINF *)0xffffffff;
  pXStack_dc = *(X509_ALGOR **)PTR___stack_chk_guard_006a9ae8;
  name = x509;
  bag = (X509 *)PKCS12_x5092certbag(x509);
  if (bag == (X509 *)0x0) {
    bag = (X509 *)0x0;
    goto LAB_005a7748;
  }
  name = (X509 *)(*(code *)PTR_X509_alias_get0_006a7708)(x509,&pXStack_e4);
  if ((name == (X509 *)0x0) ||
     (usage = pXStack_e4,
     iVar5 = PKCS12_add_friendlyname_asc((PKCS12_SAFEBAG *)bag,(char *)name,(int)pXStack_e4),
     iVar5 != 0)) {
    pXVar9 = (X509 *)&pXStack_e0;
    name = (X509 *)(*(code *)PTR_X509_keyid_get0_006a91fc)(x509,pXVar9);
    if ((name == (X509 *)0x0) ||
       (usage = pXStack_e0,
       iVar5 = PKCS12_add_localkeyid((PKCS12_SAFEBAG *)bag,(uchar *)name,(int)pXStack_e0),
       pXVar9 = name, iVar5 != 0)) {
      name = pXVar9;
      if (piVar7 == (int *)0x0) goto LAB_005a7748;
      if (*piVar7 == 0) {
        iVar5 = (*(code *)PTR_sk_new_null_006a6fa4)();
        *piVar7 = iVar5;
        if (iVar5 != 0) {
          name = bag;
          iVar5 = (*(code *)PTR_sk_push_006a6fa8)(iVar5,bag);
          if (iVar5 != 0) goto LAB_005a7748;
          (*(code *)PTR_sk_free_006a6e80)(*piVar7);
          *piVar7 = 0;
        }
      }
      else {
        name = bag;
        iVar5 = (*(code *)PTR_sk_push_006a6fa8)(*piVar7,bag);
        if (iVar5 != 0) goto LAB_005a7748;
      }
    }
  }
  PKCS12_SAFEBAG_free((PKCS12_SAFEBAG *)bag);
  bag = (X509 *)0x0;
LAB_005a7748:
  if (pXStack_dc == *(X509_ALGOR **)puVar1) {
    return (int)bag;
  }
  pXVar8 = pXStack_dc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  p8 = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_EVP_PKEY2PKCS8_006a8e9c)(name);
  if ((p8 != (PKCS8_PRIV_KEY_INFO *)0x0) &&
     ((usage == (X509_CINF *)0x0 || (iVar5 = PKCS8_add_keyusage(p8,(int)usage), iVar5 != 0)))) {
    a = PKCS12_MAKE_SHKEYBAG((int)&_gp,pcStack_ec,-1,(uchar *)0x0,0,(int)param,p8);
    (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a722c)(p8);
    if (a != (PKCS12_SAFEBAG *)0x0) {
      if (pXVar8 == (X509_ALGOR *)0x0) {
        return (int)a;
      }
      if (pXVar8->algorithm == (ASN1_OBJECT *)0x0) {
        pAVar6 = (ASN1_OBJECT *)(*(code *)PTR_sk_new_null_006a6fa4)();
        pXVar8->algorithm = pAVar6;
        if (pAVar6 != (ASN1_OBJECT *)0x0) {
          iVar5 = (*(code *)PTR_sk_push_006a6fa8)(pAVar6,a);
          if (iVar5 != 0) {
            return (int)a;
          }
          (*(code *)PTR_sk_free_006a6e80)(pXVar8->algorithm);
          pXVar8->algorithm = (ASN1_OBJECT *)0x0;
        }
      }
      else {
        iVar5 = (*(code *)PTR_sk_push_006a6fa8)(pXVar8->algorithm,a);
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

