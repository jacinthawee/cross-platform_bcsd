
EC_KEY * __regparm3 eckey_type2param(int param_1,ASN1_OBJECT *param_2)

{
  EC_KEY *key;
  EC_GROUP *group;
  int in_GS_OFFSET;
  int iVar1;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == 0x10) {
    local_14 = (uchar *)param_2->nid;
    key = d2i_ECParameters((EC_KEY **)0x0,&local_14,(long)param_2->sn);
    if (key != (EC_KEY *)0x0) goto LAB_081bc703;
    iVar1 = 0x92;
LAB_081bc6e8:
    ERR_put_error(0x10,0xdc,0x8e,"ec_ameth.c",iVar1);
  }
  else {
    if (param_1 != 6) {
      iVar1 = 0xa8;
      goto LAB_081bc6e8;
    }
    key = EC_KEY_new();
    if (key != (EC_KEY *)0x0) {
      iVar1 = OBJ_obj2nid(param_2);
      group = EC_GROUP_new_by_curve_name(iVar1);
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,1);
        iVar1 = EC_KEY_set_group(key,group);
        if (iVar1 != 0) {
          EC_GROUP_free(group);
          goto LAB_081bc703;
        }
      }
      EC_KEY_free(key);
      key = (EC_KEY *)0x0;
      goto LAB_081bc703;
    }
    ERR_put_error(0x10,0xdc,0x41,"ec_ameth.c",0x9d);
  }
  key = (EC_KEY *)0x0;
LAB_081bc703:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return key;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

