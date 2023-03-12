
X509_EXTENSION * OCSP_accept_responses_new(char **oids)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *pXVar3;
  
  iVar1 = (*(code *)PTR_sk_new_null_006a6fa4)();
  if (iVar1 == 0) {
    pXVar3 = (X509_EXTENSION *)0x0;
  }
  else {
    while (oids != (char **)0x0) {
      while( true ) {
        if (*oids == (char *)0x0) goto LAB_005ac0f4;
        oids = oids + 1;
        iVar2 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)();
        if ((iVar2 == 0) || (iVar2 = (*(code *)PTR_OBJ_nid2obj_006a7140)(iVar2), iVar2 == 0)) break;
        (*(code *)PTR_sk_push_006a6fa8)(iVar1,iVar2);
        if (oids == (char **)0x0) goto LAB_005ac0f4;
      }
    }
LAB_005ac0f4:
    pXVar3 = (X509_EXTENSION *)(*(code *)PTR_X509V3_EXT_i2d_006a9018)(0x170,0,iVar1);
    (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_ASN1_OBJECT_free_006a7004);
  }
  return pXVar3;
}

