
int PKCS7_set_digest(PKCS7 *p7,EVP_MD *md)

{
  undefined *puVar1;
  int iVar2;
  char **ppcVar3;
  undefined4 uVar4;
  ASN1_OBJECT *pAVar5;
  X509_ALGOR *pXVar6;
  stack_st_X509_ALGOR *psVar7;
  
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if (iVar2 == 0x19) {
    psVar7 = ((p7->d).sign)->md_algs;
    ppcVar3 = (char **)(*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
    (psVar7->stack).data = ppcVar3;
    puVar1 = PTR_EVP_MD_type_006a73cc;
    if (ppcVar3 != (char **)0x0) {
      pXVar6 = ((p7->d).digest)->md;
      pXVar6->parameter->type = 5;
      uVar4 = (*(code *)puVar1)(md);
      pAVar5 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(uVar4);
      pXVar6->algorithm = pAVar5;
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x7e,0x41,"pk7_lib.c",0x1b2);
    iVar2 = 0;
  }
  else {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x7e,0x71,"pk7_lib.c",0x1ba);
    iVar2 = 1;
  }
  return iVar2;
}

