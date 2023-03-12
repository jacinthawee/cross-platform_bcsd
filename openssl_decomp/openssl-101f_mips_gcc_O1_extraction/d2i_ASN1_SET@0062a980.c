
stack_st_OPENSSL_BLOCK *
d2i_ASN1_SET(stack_st_OPENSSL_BLOCK **a,uchar **pp,long length,undefined1 *d2i,free_func *free_func,
            int ex_tag,int ex_class)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  stack_st_OPENSSL_BLOCK *psVar4;
  int iVar5;
  undefined4 uVar6;
  stack_st_OPENSSL_BLOCK *psVar7;
  uchar *local_58;
  int local_54;
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  uchar *local_3c;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (((a == (stack_st_OPENSSL_BLOCK **)0x0) ||
      (psVar7 = *a, psVar7 == (stack_st_OPENSSL_BLOCK *)0x0)) &&
     (psVar7 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_sk_new_null_006a80a4)(),
     psVar7 == (stack_st_OPENSSL_BLOCK *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x94,0x41,"a_set.c",0xb3);
    psVar4 = (stack_st_OPENSSL_BLOCK *)0x0;
    goto LAB_0062aa98;
  }
  local_58 = *pp;
  if (length == 0) {
    local_3c = (uchar *)0x0;
  }
  else {
    local_3c = local_58 + length;
  }
  local_4c = (*(code *)PTR_ASN1_get_object_006a9514)
                       (&local_58,&local_40,&local_48,&local_44,(int)local_3c - (int)local_58);
  if ((local_4c & 0x80) == 0) {
    if (local_44 == ex_class) {
      if (local_48 == ex_tag) {
        if (local_58 + local_40 <= local_3c) {
          local_3c = local_58 + local_40;
          if (local_4c == 0x21) {
            local_3c = *pp + length;
            local_40 = (int)local_3c - (int)local_58;
          }
          do {
            if (local_3c <= local_58) {
LAB_0062ac1c:
              if (a != (stack_st_OPENSSL_BLOCK **)0x0) {
                *a = psVar7;
              }
              *pp = local_58;
              psVar4 = psVar7;
              goto LAB_0062aa98;
            }
            if ((local_4c & 1) == 0) {
              bVar1 = local_40 < 1;
            }
            else {
              local_54 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(&local_58,local_40);
              bVar1 = local_54 != 0;
            }
            if (bVar1) goto LAB_0062ac1c;
            iVar5 = (*(code *)d2i)(0,&local_58,local_40);
            if (iVar5 == 0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x94,0x71,"a_set.c",0xdd);
              (*(code *)PTR_asn1_add_error_006a9508)(*pp,(int)local_58 - (int)*pp);
              break;
            }
            iVar5 = (*(code *)PTR_sk_push_006a80a8)(psVar7,iVar5);
          } while (iVar5 != 0);
          goto LAB_0062aa68;
        }
        uVar6 = 0x88;
        uVar3 = 0xcb;
      }
      else {
        uVar6 = 0x68;
        uVar3 = 0xc6;
      }
    }
    else {
      uVar6 = 0x65;
      uVar3 = 0xc1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x94,uVar6,"a_set.c",uVar3);
  }
LAB_0062aa68:
  if ((a == (stack_st_OPENSSL_BLOCK **)0x0) ||
     (psVar4 = (stack_st_OPENSSL_BLOCK *)0x0, psVar7 != *a)) {
    if (free_func == (free_func *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(psVar7);
      psVar4 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
    else {
      (*(code *)PTR_sk_pop_free_006a8158)(psVar7,free_func);
      psVar4 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
  }
LAB_0062aa98:
  if (local_2c == *(int *)puVar2) {
    return psVar4;
  }
  iVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(iVar5 + 0x24) == 0) {
    return (stack_st_OPENSSL_BLOCK *)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x0062acb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  psVar7 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_BIO_callback_ctrl_006a9548)();
  return psVar7;
}

