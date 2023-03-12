
stack_st_X509_EXTENSION * X509_REQ_get_extensions(X509_REQ *req)

{
  undefined *puVar1;
  stack_st_X509_EXTENSION *psVar2;
  X509_ATTRIBUTE *pXVar3;
  stack_st_ASN1_TYPE *psVar4;
  char **ppcVar5;
  ASN1_TYPE *a;
  ASN1_STRING *pAVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int *piVar10;
  uchar **in_a1;
  char *in_a2;
  int iVar11;
  uchar *local_18;
  int *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  piVar10 = (int *)ext_nids;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  psVar2 = (stack_st_X509_EXTENSION *)0x0;
  if (req != (X509_REQ *)0x0) {
    if (((req->req_info != (X509_REQ_INFO *)0x0) && (ext_nids != (undefined *)0x0)) &&
       (in_a1 = *(uchar ***)ext_nids, in_a1 != (uchar **)0x0)) {
      in_a2 = (char *)0xffffffff;
      for (in_a1 = (uchar **)X509at_get_attr_by_NID(req->req_info->attributes,(int)in_a1,-1);
          in_a1 == (uchar **)0xffffffff;
          in_a1 = (uchar **)X509at_get_attr_by_NID(req->req_info->attributes,(int)in_a1,-1)) {
        piVar10 = piVar10 + 1;
        in_a1 = (uchar **)*piVar10;
        in_a2 = (char *)0xffffffff;
        if (in_a1 == (uchar **)0x0) goto LAB_0057a574;
      }
      pXVar3 = X509at_get_attr(req->req_info->attributes,(int)in_a1);
      if (pXVar3->single == 0) {
        iVar7 = (*(code *)PTR_sk_num_006a7f2c)((pXVar3->value).ptr);
        if (iVar7 == 0) goto LAB_0057a574;
        in_a1 = (uchar **)0x0;
        psVar4 = (stack_st_ASN1_TYPE *)(*(code *)PTR_sk_value_006a7f24)((pXVar3->value).ptr);
      }
      else {
        psVar4 = (pXVar3->value).set;
      }
      if ((psVar4 != (stack_st_ASN1_TYPE *)0x0) && (in_a1 = &local_18, (psVar4->stack).num == 0x10))
      {
        ppcVar5 = (psVar4->stack).data;
        local_18 = (uchar *)ppcVar5[2];
        in_a2 = *ppcVar5;
        psVar2 = (stack_st_X509_EXTENSION *)
                 ASN1_item_d2i((ASN1_VALUE **)0x0,in_a1,(long)in_a2,
                               (ASN1_ITEM *)PTR_X509_EXTENSIONS_it_006a9fdc);
        goto LAB_0057a53c;
      }
    }
LAB_0057a574:
    psVar2 = (stack_st_X509_EXTENSION *)0x0;
  }
LAB_0057a53c:
  if (local_14 == *(int **)puVar1) {
    return psVar2;
  }
  piVar10 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  a = ASN1_TYPE_new();
  if (a != (ASN1_TYPE *)0x0) {
    pAVar6 = ASN1_STRING_new();
    (a->value).asn1_string = pAVar6;
    puVar1 = PTR_X509_EXTENSIONS_it_006a9fdc;
    if (pAVar6 != (ASN1_STRING *)0x0) {
      a->type = 0x10;
      iVar7 = ASN1_item_i2d((ASN1_VALUE *)in_a1,&pAVar6->data,(ASN1_ITEM *)puVar1);
      puVar1 = PTR_X509_ATTRIBUTE_new_006a9fe0;
      pAVar6->length = iVar7;
      puVar8 = (undefined4 *)(*(code *)puVar1)();
      if (puVar8 == (undefined4 *)0x0) goto LAB_0057a66c;
      iVar7 = (*(code *)PTR_sk_new_null_006a80a4)();
      puVar8[2] = iVar7;
      if ((iVar7 == 0) ||
         (iVar7 = (*(code *)PTR_sk_push_006a80a8)(iVar7,a), puVar1 = PTR_OBJ_nid2obj_006a8240,
         iVar7 == 0)) goto LAB_0057a66c;
      puVar8[1] = 0;
      uVar9 = (*(code *)puVar1)(in_a2);
      iVar11 = *piVar10;
      *puVar8 = uVar9;
      iVar7 = *(int *)(iVar11 + 0x18);
      if (iVar7 == 0) {
        iVar7 = (*(code *)PTR_sk_new_null_006a80a4)();
        *(int *)(iVar11 + 0x18) = iVar7;
        if (iVar7 != 0) {
          iVar7 = *(int *)(*piVar10 + 0x18);
          goto LAB_0057a6dc;
        }
      }
      else {
LAB_0057a6dc:
        iVar7 = (*(code *)PTR_sk_push_006a80a8)(iVar7,puVar8);
        if (iVar7 != 0) {
          return (stack_st_X509_EXTENSION *)0x1;
        }
      }
      a = (ASN1_TYPE *)0x0;
      goto LAB_0057a66c;
    }
  }
  puVar8 = (undefined4 *)0x0;
LAB_0057a66c:
  (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(puVar8);
  ASN1_TYPE_free(a);
  return (stack_st_X509_EXTENSION *)0x0;
}

