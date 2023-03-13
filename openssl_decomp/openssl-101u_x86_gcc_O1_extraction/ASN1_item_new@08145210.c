
ASN1_VALUE * ASN1_item_new(ASN1_ITEM *it)

{
  code **ppcVar1;
  uint uVar2;
  ASN1_VALUE *pAVar3;
  ASN1_VALUE *pAVar4;
  _STACK **pp_Var5;
  _STACK *p_Var6;
  int iVar7;
  ASN1_TEMPLATE *tt;
  int iVar8;
  int in_GS_OFFSET;
  code *local_34;
  ASN1_VALUE *local_24;
  int local_20;
  
  local_24 = (ASN1_VALUE *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ppcVar1 = (code **)it->funcs;
  if (ppcVar1 == (code **)0x0) {
    switch(it->itype) {
    case '\0':
switchD_081454ac_caseD_0:
      if (it->templates != (ASN1_TEMPLATE *)0x0) {
        pAVar3 = (ASN1_VALUE *)ASN1_template_new(&local_24,it->templates);
        break;
      }
    case '\x05':
switchD_081454ac_caseD_5:
      pAVar3 = (ASN1_VALUE *)ASN1_primitive_new(&local_24,it);
      break;
    case '\x01':
    case '\x06':
      local_34 = (code *)0x0;
      goto LAB_081453d4;
    case '\x02':
switchD_081454ac_caseD_2:
      local_24 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0x9a);
      if (local_24 != (ASN1_VALUE *)0x0) {
        memset(local_24,0,it->size);
        asn1_set_choice_selector(&local_24,-1,it);
        pAVar4 = local_24;
        goto LAB_08145282;
      }
      goto LAB_08145265;
    default:
      goto switchD_081454ac_caseD_3;
    }
    goto joined_r0x081452d8;
  }
  local_34 = ppcVar1[4];
  if (6 < (byte)it->itype) goto switchD_081454ac_caseD_3;
  switch(it->itype) {
  case '\0':
    goto switchD_081454ac_caseD_0;
  default:
    if (local_34 == (code *)0x0) {
LAB_081453d4:
      local_24 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0xb3);
      if (local_24 == (ASN1_VALUE *)0x0) goto LAB_08145265;
      iVar8 = 0;
      memset(local_24,0,it->size);
      asn1_do_lock(&local_24,0,it);
      asn1_enc_init(&local_24,it);
      tt = it->templates;
      if (0 < it->tcount) {
        do {
          pp_Var5 = (_STACK **)asn1_get_field_ptr(&local_24,tt);
          uVar2 = tt->flags;
          if ((uVar2 & 1) == 0) {
            if ((uVar2 & 0x300) == 0) {
              if ((uVar2 & 6) == 0) {
                iVar7 = asn1_item_ex_combine_new();
                if (iVar7 == 0) goto LAB_08145265;
              }
              else {
                p_Var6 = sk_new_null();
                if (p_Var6 == (_STACK *)0x0) {
                  ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x115);
                  goto LAB_08145265;
                }
                *pp_Var5 = p_Var6;
              }
            }
            else {
LAB_0814544c:
              *pp_Var5 = (_STACK *)0x0;
            }
          }
          else {
            if ((uVar2 & 0x306) != 0) goto LAB_0814544c;
            asn1_item_clear();
          }
          tt = tt + 1;
          iVar8 = iVar8 + 1;
        } while (iVar8 < it->tcount);
      }
      pAVar4 = local_24;
      if (local_34 == (code *)0x0) goto LAB_08145282;
      iVar8 = (*local_34)(1,&local_24,it,0);
      pAVar4 = local_24;
      goto joined_r0x0814537b;
    }
    iVar8 = (*local_34)(0,&local_24,it,0);
    if (iVar8 != 0) {
      pAVar4 = local_24;
      if (iVar8 == 2) goto LAB_08145282;
      goto LAB_081453d4;
    }
    goto LAB_08145381;
  case '\x02':
    if (local_34 == (code *)0x0) goto switchD_081454ac_caseD_2;
    iVar8 = (*local_34)(0,&local_24,it,0);
    if (iVar8 == 0) goto LAB_08145381;
    pAVar4 = local_24;
    if (iVar8 == 2) goto LAB_08145282;
    local_24 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0x9a);
    if (local_24 == (ASN1_VALUE *)0x0) goto LAB_08145265;
    memset(local_24,0,it->size);
    asn1_set_choice_selector(&local_24,-1,it);
    iVar8 = (*local_34)(1,&local_24,it,0);
    pAVar4 = local_24;
joined_r0x0814537b:
    local_24 = pAVar4;
    if (iVar8 != 0) goto LAB_08145282;
LAB_08145381:
    ERR_put_error(0xd,0x79,100,"tasn_new.c",0xd2);
    ASN1_item_ex_free(&local_24,it);
    goto switchD_081454ac_caseD_3;
  case '\x03':
    pAVar4 = (ASN1_VALUE *)0x0;
    if (*ppcVar1 == (code *)0x0) goto LAB_08145282;
    local_24 = (ASN1_VALUE *)(**ppcVar1)();
    pAVar3 = local_24;
    break;
  case '\x04':
    pAVar4 = (ASN1_VALUE *)0x0;
    if (ppcVar1[1] == (code *)0x0) goto LAB_08145282;
    pAVar3 = (ASN1_VALUE *)(*ppcVar1[1])(&local_24,it);
    break;
  case '\x05':
    goto switchD_081454ac_caseD_5;
  }
joined_r0x081452d8:
  pAVar4 = local_24;
  if (pAVar3 == (ASN1_VALUE *)0x0) {
LAB_08145265:
    ERR_put_error(0xd,0x79,0x41,"tasn_new.c",0xca);
switchD_081454ac_caseD_3:
    pAVar4 = (ASN1_VALUE *)0x0;
  }
LAB_08145282:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pAVar4;
}

