
void ASN1_item_free(ASN1_VALUE *val,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_TEMPLATE *pAVar2;
  _STACK **pp_Var3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  _STACK *p_Var7;
  ASN1_TEMPLATE *pAVar8;
  code *pcVar9;
  int unaff_r9;
  ASN1_VALUE *local_34 [2];
  void *local_2c [2];
  
  pcVar5 = (code *)it->funcs;
  if ((it->itype != '\0') && (val == (ASN1_VALUE *)0x0)) {
    return;
  }
  pcVar9 = pcVar5;
  if (pcVar5 != (code *)0x0) {
    pcVar9 = *(code **)(pcVar5 + 0x10);
  }
  local_34[0] = val;
  switch(it->itype) {
  case '\0':
    pAVar8 = it->templates;
    if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto switchD_000bbf1e_caseD_5;
    if ((pAVar8->flags & 6) == 0) {
      asn1_item_combine_free(local_34,pAVar8->item,pAVar8->flags & 0x400);
    }
    else {
      iVar1 = 0;
      while( true ) {
        iVar4 = sk_num((_STACK *)val);
        if (iVar4 <= iVar1) break;
        local_2c[0] = sk_value((_STACK *)val,iVar1);
        asn1_item_combine_free(local_2c,pAVar8->item,0);
        iVar1 = iVar1 + 1;
      }
      sk_free((_STACK *)val);
    }
    break;
  case '\x01':
  case '\x06':
    iVar1 = asn1_do_lock(local_34,-1,it);
    if (0 < iVar1) {
      return;
    }
    if ((pcVar9 != (code *)0x0) && (iVar1 = (*pcVar9)(2,local_34,it,0), iVar1 == 2)) {
      return;
    }
    asn1_enc_free(local_34,it);
    iVar1 = it->tcount;
    if (0 < iVar1) {
      unaff_r9 = 0;
    }
    pAVar8 = it->templates + iVar1 + -1;
    if (0 < iVar1) {
      do {
        pAVar2 = asn1_do_adb(local_34,pAVar8,0);
        if (pAVar2 != (ASN1_TEMPLATE *)0x0) {
          pp_Var3 = (_STACK **)asn1_get_field_ptr(local_34,pAVar2);
          if ((pAVar2->flags & 6) == 0) {
            asn1_item_combine_free(pp_Var3,pAVar2->item,pAVar2->flags & 0x400);
          }
          else {
            p_Var7 = *pp_Var3;
            iVar1 = 0;
            while( true ) {
              iVar4 = sk_num(p_Var7);
              if (iVar4 <= iVar1) break;
              local_2c[0] = sk_value(p_Var7,iVar1);
              asn1_item_combine_free(local_2c,pAVar2->item,0);
              iVar1 = iVar1 + 1;
            }
            sk_free(p_Var7);
            *pp_Var3 = (_STACK *)0x0;
          }
        }
        unaff_r9 = unaff_r9 + 1;
        pAVar8 = pAVar8 + -1;
      } while (unaff_r9 < it->tcount);
    }
    goto LAB_000bbf36;
  case '\x02':
    if ((pcVar9 != (code *)0x0) && (iVar1 = (*pcVar9)(2,local_34,it,0), iVar1 == 2)) {
      return;
    }
    iVar1 = asn1_get_choice_selector(local_34,it);
    if ((-1 < iVar1) && (iVar1 < it->tcount)) {
      pAVar8 = it->templates;
      pAVar2 = pAVar8 + iVar1;
      pp_Var3 = (_STACK **)asn1_get_field_ptr(local_34,pAVar2);
      uVar6 = pAVar8[iVar1].flags;
      if ((uVar6 & 6) == 0) {
        asn1_item_combine_free(pp_Var3,pAVar2->item,uVar6 & 0x400);
      }
      else {
        p_Var7 = *pp_Var3;
        iVar1 = 0;
        while( true ) {
          iVar4 = sk_num(p_Var7);
          if (iVar4 <= iVar1) break;
          local_2c[0] = sk_value(p_Var7,iVar1);
          asn1_item_combine_free(local_2c,pAVar2->item,0);
          iVar1 = iVar1 + 1;
        }
        sk_free(p_Var7);
        *pp_Var3 = (_STACK *)0x0;
      }
    }
LAB_000bbf36:
    if (pcVar9 != (code *)0x0) {
      (*pcVar9)(3,local_34,it,0);
    }
    CRYPTO_free(local_34[0]);
    break;
  case '\x03':
    if ((pcVar5 != (code *)0x0) && (*(code **)(pcVar5 + 4) != (code *)0x0)) {
      (**(code **)(pcVar5 + 4))(val);
    }
    break;
  case '\x04':
    if ((pcVar5 != (code *)0x0) && (*(code **)(pcVar5 + 8) != (code *)0x0)) {
      (**(code **)(pcVar5 + 8))(local_34,it);
    }
    break;
  case '\x05':
switchD_000bbf1e_caseD_5:
    ASN1_primitive_free(local_34,it);
    return;
  }
  return;
}

