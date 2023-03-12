
/* WARNING: Type propagation algorithm not settling */

ASN1_VALUE * ASN1_item_new(ASN1_ITEM *it)

{
  undefined *puVar1;
  ASN1_VALUE *pAVar2;
  ASN1_VALUE **ppAVar3;
  ASN1_VALUE *pAVar4;
  int iVar5;
  ASN1_STRING *pAVar6;
  int iVar7;
  code **ppcVar8;
  int *piVar9;
  ASN1_OBJECT *a;
  ASN1_ITEM *in_a1;
  uint uVar10;
  ASN1_TEMPLATE *tt;
  code *pcVar11;
  ASN1_VALUE *local_30;
  int *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  ppcVar8 = (code **)it->funcs;
  local_30 = (ASN1_VALUE *)0x0;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (ppcVar8 == (code **)0x0) {
    switch(it->itype) {
    case '\0':
      goto switchD_0055eecc_caseD_0;
    case '\x01':
    case '\x06':
      pcVar11 = (code *)0x0;
      goto LAB_0055ed98;
    case '\x02':
      goto switchD_0055eecc_caseD_2;
    default:
      goto switchD_0055eecc_caseD_3;
    case '\x05':
      goto LAB_0055ebd8;
    }
  }
  pcVar11 = ppcVar8[4];
  switch(it->itype) {
  case '\0':
switchD_0055eecc_caseD_0:
    in_a1 = (ASN1_ITEM *)it->templates;
    if (in_a1 == (ASN1_ITEM *)0x0) goto LAB_0055ebd8;
    pAVar4 = (ASN1_VALUE *)ASN1_template_new(&local_30,(ASN1_TEMPLATE *)in_a1);
    goto joined_r0x0055ec88;
  case '\x01':
  case '\x06':
    if (pcVar11 == (code *)0x0) {
LAB_0055ed98:
      local_30 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(it->size,"tasn_new.c",0xbf);
      if (local_30 == (ASN1_VALUE *)0x0) goto LAB_0055ebf0;
      iVar7 = 0;
      (*(code *)PTR_memset_006aab00)(local_30,0,it->size);
      asn1_do_lock(&local_30,0,it);
      in_a1 = it;
      asn1_enc_init(&local_30,it);
      tt = it->templates;
      if (0 < it->tcount) {
        do {
          ppAVar3 = asn1_get_field_ptr(&local_30,tt);
          uVar10 = tt->flags;
          in_a1 = tt->item;
          if ((uVar10 & 1) == 0) {
            if ((uVar10 & 0x300) != 0) goto LAB_0055ee48;
            if ((uVar10 & 6) == 0) {
              iVar5 = asn1_item_ex_combine_new(ppAVar3,in_a1,uVar10 & 0x400);
              if (iVar5 == 0) goto LAB_0055ebf0;
            }
            else {
              pAVar4 = (ASN1_VALUE *)(*(code *)PTR_sk_new_null_006a80a4)();
              if (pAVar4 == (ASN1_VALUE *)0x0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x85,0x41,"tasn_new.c",0x125);
                goto LAB_0055ebf0;
              }
              *ppAVar3 = pAVar4;
            }
          }
          else if ((uVar10 & 0x306) == 0) {
            asn1_item_clear(ppAVar3);
          }
          else {
LAB_0055ee48:
            *ppAVar3 = (ASN1_VALUE *)0x0;
          }
          iVar7 = iVar7 + 1;
          tt = tt + 1;
        } while (iVar7 < it->tcount);
      }
      pAVar2 = local_30;
      if (pcVar11 == (code *)0x0) goto LAB_0055ec14;
      goto LAB_0055ed44;
    }
    in_a1 = (ASN1_ITEM *)&local_30;
    iVar7 = (*pcVar11)(0,in_a1,it,0);
    if (iVar7 != 0) {
      pAVar2 = local_30;
      if (iVar7 == 2) goto LAB_0055ec14;
      goto LAB_0055ed98;
    }
LAB_0055eef8:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x79,100,"tasn_new.c",0xdd);
    ASN1_item_ex_free(&local_30,it);
    in_a1 = it;
    break;
  case '\x02':
    if (pcVar11 == (code *)0x0) goto switchD_0055eecc_caseD_2;
    in_a1 = (ASN1_ITEM *)&local_30;
    iVar7 = (*pcVar11)(0,(ASN1_ITEM *)&local_30,it,0);
    if (iVar7 == 0) goto LAB_0055eef8;
    pAVar2 = local_30;
    if (iVar7 == 2) goto LAB_0055ec14;
    local_30 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(it->size,"tasn_new.c",0xa3);
    if (local_30 == (ASN1_VALUE *)0x0) goto LAB_0055ebf0;
    (*(code *)PTR_memset_006aab00)(local_30,0,it->size);
    asn1_set_choice_selector((ASN1_VALUE **)(ASN1_ITEM *)&local_30,-1,it);
LAB_0055ed44:
    in_a1 = (ASN1_ITEM *)&local_30;
    iVar7 = (*pcVar11)(1,in_a1,it,0);
    pAVar2 = local_30;
    if (iVar7 == 0) goto LAB_0055eef8;
    goto LAB_0055ec14;
  case '\x03':
    pAVar2 = (ASN1_VALUE *)0x0;
    if (*ppcVar8 == (code *)0x0) goto LAB_0055ec14;
    local_30 = (ASN1_VALUE *)(**ppcVar8)();
    pAVar4 = local_30;
    goto joined_r0x0055ec88;
  case '\x04':
    if (ppcVar8[1] != (code *)0x0) {
      pAVar4 = (ASN1_VALUE *)(*ppcVar8[1])(&local_30);
      in_a1 = it;
      goto joined_r0x0055ec88;
    }
    break;
  case '\x05':
LAB_0055ebd8:
    pAVar4 = (ASN1_VALUE *)ASN1_primitive_new(&local_30,it);
    in_a1 = it;
joined_r0x0055ec88:
    pAVar2 = local_30;
    if (pAVar4 == (ASN1_VALUE *)0x0) {
LAB_0055ebf0:
      in_a1 = (ASN1_ITEM *)0x79;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x79,0x41,"tasn_new.c",0xd6);
      break;
    }
    goto LAB_0055ec14;
  }
switchD_0055eecc_caseD_3:
  pAVar2 = (ASN1_VALUE *)0x0;
LAB_0055ec14:
  if ((ASN1_VALUE **)local_2c == *(ASN1_VALUE ***)puVar1) {
    return pAVar2;
  }
  piVar9 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (in_a1 == (ASN1_ITEM *)0x0) {
    pAVar6 = (ASN1_STRING *)*piVar9;
    piVar9 = &pAVar6->type;
    a = (ASN1_OBJECT *)pAVar6->type;
    iVar7 = pAVar6->length;
    if (a == (ASN1_OBJECT *)0x0) {
      return (ASN1_VALUE *)pAVar6;
    }
    if (iVar7 == 1) {
      pAVar6->type = -1;
      return (ASN1_VALUE *)pAVar6;
    }
    if (1 < iVar7) {
      pAVar6 = (ASN1_STRING *)&DAT_00000006;
      if (iVar7 == 5) goto LAB_0055f050;
      if (iVar7 == 6) goto LAB_0055f0d8;
      goto LAB_0055f070;
    }
  }
  else {
    pAVar6 = (ASN1_STRING *)&DAT_00000005;
    if (in_a1->itype == '\x05') {
      a = (ASN1_OBJECT *)*piVar9;
      if (a == (ASN1_OBJECT *)0x0) {
        return (ASN1_VALUE *)pAVar6;
      }
      goto LAB_0055f070;
    }
    iVar7 = in_a1->utype;
    if (iVar7 == 1) {
      pAVar6 = (ASN1_STRING *)in_a1->size;
      *piVar9 = (int)pAVar6;
      return (ASN1_VALUE *)pAVar6;
    }
    a = (ASN1_OBJECT *)*piVar9;
    if (a == (ASN1_OBJECT *)0x0) {
      return (ASN1_VALUE *)pAVar6;
    }
    pAVar6 = (ASN1_STRING *)&DAT_00000006;
    if (iVar7 == 5) goto LAB_0055f050;
    if (iVar7 == 6) {
LAB_0055f0d8:
      pAVar6 = (ASN1_STRING *)&DAT_00000006;
      ASN1_OBJECT_free(a);
      *piVar9 = 0;
      return (ASN1_VALUE *)pAVar6;
    }
  }
  pAVar6 = (ASN1_STRING *)0xfffffffc;
  if (iVar7 == -4) {
    ASN1_primitive_free_part_0(piVar9,0);
    pAVar6 = (ASN1_STRING *)(*(code *)PTR_CRYPTO_free_006a7f88)((ASN1_STRING *)*piVar9);
LAB_0055f050:
    *piVar9 = 0;
    return (ASN1_VALUE *)pAVar6;
  }
LAB_0055f070:
  ASN1_STRING_free((ASN1_STRING *)a);
  *piVar9 = 0;
  return (ASN1_VALUE *)pAVar6;
switchD_0055eecc_caseD_2:
  local_30 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(it->size,"tasn_new.c",0xa3);
  if (local_30 != (ASN1_VALUE *)0x0) {
    (*(code *)PTR_memset_006aab00)(local_30,0,it->size);
    in_a1 = (ASN1_ITEM *)0xffffffff;
    asn1_set_choice_selector(&local_30,-1,it);
    pAVar2 = local_30;
    goto LAB_0055ec14;
  }
  goto LAB_0055ebf0;
}
