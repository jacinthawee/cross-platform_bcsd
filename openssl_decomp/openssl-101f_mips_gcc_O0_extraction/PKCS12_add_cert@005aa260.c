
/* WARNING: Removing unreachable block (ram,0x005aa560) */

PKCS12_SAFEBAG * PKCS12_add_cert(stack_st_PKCS12_SAFEBAG **pbags,X509 *cert)

{
  undefined *puVar1;
  X509 *bag;
  X509 *name;
  int iVar2;
  stack_st_PKCS12_SAFEBAG *psVar3;
  PKCS8_PRIV_KEY_INFO *p8;
  PKCS12_SAFEBAG *a;
  ASN1_OBJECT *pAVar4;
  X509_ALGOR *pXVar5;
  X509 *pXVar6;
  X509_CINF *in_a2;
  int in_a3;
  char *pcStack_2c;
  X509_CINF *local_24;
  X509_CINF *local_20;
  X509_ALGOR *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = (X509_CINF *)0xffffffff;
  local_20 = (X509_CINF *)0xffffffff;
  local_1c = *(X509_ALGOR **)PTR___stack_chk_guard_006aabf0;
  name = cert;
  bag = (X509 *)PKCS12_x5092certbag(cert);
  if (bag == (X509 *)0x0) {
    bag = (X509 *)0x0;
    goto LAB_005aa308;
  }
  name = (X509 *)(*(code *)PTR_X509_alias_get0_006a87fc)(cert,&local_24);
  if ((name == (X509 *)0x0) ||
     (in_a2 = local_24,
     iVar2 = PKCS12_add_friendlyname_asc((PKCS12_SAFEBAG *)bag,(char *)name,(int)local_24),
     iVar2 != 0)) {
    pXVar6 = (X509 *)&local_20;
    name = (X509 *)(*(code *)PTR_X509_keyid_get0_006aa314)(cert,pXVar6);
    if ((name == (X509 *)0x0) ||
       (in_a2 = local_20,
       iVar2 = PKCS12_add_localkeyid((PKCS12_SAFEBAG *)bag,(uchar *)name,(int)local_20),
       pXVar6 = name, iVar2 != 0)) {
      name = pXVar6;
      if (pbags == (stack_st_PKCS12_SAFEBAG **)0x0) goto LAB_005aa308;
      if (*pbags == (stack_st_PKCS12_SAFEBAG *)0x0) {
        psVar3 = (stack_st_PKCS12_SAFEBAG *)(*(code *)PTR_sk_new_null_006a80a4)();
        *pbags = psVar3;
        if (psVar3 != (stack_st_PKCS12_SAFEBAG *)0x0) {
          name = bag;
          iVar2 = (*(code *)PTR_sk_push_006a80a8)(psVar3,bag);
          if (iVar2 != 0) goto LAB_005aa308;
          (*(code *)PTR_sk_free_006a7f80)(*pbags);
          *pbags = (stack_st_PKCS12_SAFEBAG *)0x0;
        }
      }
      else {
        name = bag;
        iVar2 = (*(code *)PTR_sk_push_006a80a8)(*pbags,bag);
        if (iVar2 != 0) goto LAB_005aa308;
      }
    }
  }
  PKCS12_SAFEBAG_free((PKCS12_SAFEBAG *)bag);
  bag = (X509 *)0x0;
LAB_005aa308:
  if (local_1c == *(X509_ALGOR **)puVar1) {
    return (PKCS12_SAFEBAG *)bag;
  }
  pXVar5 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  p8 = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_EVP_PKEY2PKCS8_006a9fb8)(name);
  if ((p8 != (PKCS8_PRIV_KEY_INFO *)0x0) &&
     ((in_a2 == (X509_CINF *)0x0 || (iVar2 = PKCS8_add_keyusage(p8,(int)in_a2), iVar2 != 0)))) {
    a = PKCS12_MAKE_SHKEYBAG((int)&_gp,pcStack_2c,-1,(uchar *)0x0,0,in_a3,p8);
    (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a8340)(p8);
    if (a != (PKCS12_SAFEBAG *)0x0) {
      if (pXVar5 == (X509_ALGOR *)0x0) {
        return a;
      }
      if (pXVar5->algorithm == (ASN1_OBJECT *)0x0) {
        pAVar4 = (ASN1_OBJECT *)(*(code *)PTR_sk_new_null_006a80a4)();
        pXVar5->algorithm = pAVar4;
        if (pAVar4 != (ASN1_OBJECT *)0x0) {
          iVar2 = (*(code *)PTR_sk_push_006a80a8)(pAVar4,a);
          if (iVar2 != 0) {
            return a;
          }
          (*(code *)PTR_sk_free_006a7f80)(pXVar5->algorithm);
          pXVar5->algorithm = (ASN1_OBJECT *)0x0;
        }
      }
      else {
        iVar2 = (*(code *)PTR_sk_push_006a80a8)(pXVar5->algorithm,a);
        if (iVar2 != 0) {
          return a;
        }
      }
      PKCS12_SAFEBAG_free(a);
      return (PKCS12_SAFEBAG *)0x0;
    }
  }
  return (PKCS12_SAFEBAG *)0x0;
}

