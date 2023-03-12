
/* WARNING: Type propagation algorithm not settling */

ASN1_VALUE * ASN1_item_new(ASN1_ITEM *it)

{
  code **ppcVar1;
  int iVar2;
  _STACK **pp_Var3;
  _STACK *p_Var4;
  int iVar5;
  uint uVar6;
  ASN1_TEMPLATE *pAVar7;
  code **ppcVar8;
  _STACK *local_24;
  
  ppcVar1 = (code **)it->funcs;
  local_24 = (_STACK *)0x0;
  ppcVar8 = ppcVar1;
  if (ppcVar1 != (code **)0x0) {
    ppcVar8 = (code **)ppcVar1[4];
  }
  switch(it->itype) {
  case '\0':
    pAVar7 = it->templates;
    if (pAVar7 == (ASN1_TEMPLATE *)0x0) goto switchD_000bb92e_caseD_5;
    uVar6 = pAVar7->flags;
    if ((uVar6 & 1) != 0) {
      if ((uVar6 & 0x306) != 0) {
        return (ASN1_VALUE *)0;
      }
      asn1_item_clear(&local_24);
      return (ASN1_VALUE *)local_24;
    }
    if ((uVar6 & 0x300) != 0) {
      return (ASN1_VALUE *)0x0;
    }
    if ((uVar6 & 6) == 0) {
      iVar2 = asn1_item_ex_combine_new(&local_24,pAVar7->item,uVar6 & 0x400);
      goto joined_r0x000bb948;
    }
    p_Var4 = sk_new_null();
    if (p_Var4 != (_STACK *)0x0) {
      return (ASN1_VALUE *)p_Var4;
    }
LAB_000bbb08:
    ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x125);
    break;
  case '\x01':
  case '\x06':
    if (ppcVar8 != (code **)0x0) {
      iVar2 = (*(code *)ppcVar8)(0,&local_24,it,0);
      if (iVar2 == 0) goto LAB_000bbabc;
      if (iVar2 == 2) {
        return (ASN1_VALUE *)local_24;
      }
    }
    local_24 = (_STACK *)CRYPTO_malloc(it->size,"tasn_new.c",0xbf);
    if (local_24 != (_STACK *)0x0) {
      memset(local_24,0,it->size);
      asn1_do_lock((ASN1_VALUE **)&local_24,0,it);
      asn1_enc_init((ASN1_VALUE **)&local_24,it);
      pAVar7 = it->templates;
      if (0 < it->tcount) {
        iVar2 = 0;
        do {
          pp_Var3 = (_STACK **)asn1_get_field_ptr((ASN1_VALUE **)&local_24,pAVar7);
          uVar6 = pAVar7->flags;
          if ((uVar6 & 1) == 0) {
            if ((uVar6 & 0x300) == 0) {
              if ((uVar6 & 6) == 0) {
                iVar5 = asn1_item_ex_combine_new(pp_Var3,pAVar7->item,uVar6 & 0x400);
                if (iVar5 == 0) goto LAB_000bb94a;
              }
              else {
                p_Var4 = sk_new_null();
                if (p_Var4 == (_STACK *)0x0) goto LAB_000bbb08;
                *pp_Var3 = p_Var4;
              }
            }
            else {
              *pp_Var3 = (_STACK *)0x0;
            }
          }
          else if ((uVar6 & 0x306) == 0) {
            asn1_item_clear(pp_Var3,pAVar7->item);
          }
          else {
            *pp_Var3 = (_STACK *)0x0;
          }
          iVar2 = iVar2 + 1;
          pAVar7 = pAVar7 + 1;
        } while (iVar2 < it->tcount);
      }
joined_r0x000bbaa8:
      if (ppcVar8 == (code **)0x0) {
        return (ASN1_VALUE *)local_24;
      }
      iVar2 = (*(code *)ppcVar8)(1,&local_24,it,0);
      if (iVar2 != 0) {
        return (ASN1_VALUE *)local_24;
      }
LAB_000bbabc:
      ERR_put_error(0xd,0x79,100,"tasn_new.c",0xdd);
      ASN1_item_ex_free((ASN1_VALUE **)&local_24,it);
      return (ASN1_VALUE *)0;
    }
    break;
  case '\x02':
    if (ppcVar8 != (code **)0x0) {
      iVar2 = (*(code *)ppcVar8)(0,&local_24,it,0);
      if (iVar2 == 0) goto LAB_000bbabc;
      if (iVar2 == 2) {
        return (ASN1_VALUE *)local_24;
      }
    }
    local_24 = (_STACK *)CRYPTO_malloc(it->size,"tasn_new.c",0xa3);
    if (local_24 != (_STACK *)0x0) {
      memset(local_24,0,it->size);
      asn1_set_choice_selector((ASN1_VALUE **)&local_24,-1,it);
      goto joined_r0x000bbaa8;
    }
    break;
  case '\x03':
    if (ppcVar1 == (code **)0x0) {
      return (ASN1_VALUE *)0x0;
    }
    if (*ppcVar1 == (code *)0x0) {
      return (ASN1_VALUE *)0x0;
    }
    local_24 = (_STACK *)(**ppcVar1)();
    if (local_24 != (_STACK *)0x0) {
      return (ASN1_VALUE *)local_24;
    }
    break;
  case '\x04':
    if (ppcVar1 == (code **)0x0) {
      return (ASN1_VALUE *)0x0;
    }
    if (ppcVar1[1] == (code *)0x0) {
      return (ASN1_VALUE *)0x0;
    }
    iVar2 = (*ppcVar1[1])(&local_24,it);
    goto joined_r0x000bb948;
  case '\x05':
switchD_000bb92e_caseD_5:
    iVar2 = ASN1_primitive_new((ASN1_VALUE **)&local_24,it);
joined_r0x000bb948:
    if (iVar2 != 0) {
      return (ASN1_VALUE *)local_24;
    }
    break;
  default:
    goto LAB_000bb962;
  }
LAB_000bb94a:
  ERR_put_error(0xd,0x79,0x41,"tasn_new.c",0xd6);
LAB_000bb962:
  return (ASN1_VALUE *)0x0;
}

