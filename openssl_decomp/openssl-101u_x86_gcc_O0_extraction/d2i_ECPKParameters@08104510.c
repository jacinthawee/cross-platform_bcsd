
EC_GROUP * d2i_ECPKParameters(EC_GROUP **param_1,uchar **in,long len)

{
  int *val;
  int iVar1;
  EC_GROUP *group;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *in;
  val = (int *)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_24,len,(ASN1_ITEM *)ECPKPARAMETERS_it);
  if (val == (int *)0x0) {
    group = (EC_GROUP *)0x0;
    ERR_put_error(0x10,0x91,0x75,"ec_asn1.c",0x3d0);
    ASN1_item_free((ASN1_VALUE *)0x0,(ASN1_ITEM *)ECPKPARAMETERS_it);
    goto LAB_081045b4;
  }
  iVar1 = *val;
  if (iVar1 == 0) {
    iVar1 = OBJ_obj2nid((ASN1_OBJECT *)val[1]);
    group = EC_GROUP_new_by_curve_name(iVar1);
    if (group != (EC_GROUP *)0x0) {
      EC_GROUP_set_asn1_flag(group,1);
LAB_081045fe:
      if (param_1 != (EC_GROUP **)0x0) {
        if (*param_1 != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*param_1);
        }
        *param_1 = group;
      }
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)ECPKPARAMETERS_it);
      *in = local_24;
      goto LAB_081045b4;
    }
    ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x3b1);
  }
  else if (iVar1 == 1) {
    group = (EC_GROUP *)ec_asn1_parameters2group();
    if (group != (EC_GROUP *)0x0) {
      EC_GROUP_set_asn1_flag(group,0);
      goto LAB_081045fe;
    }
    ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x3b9);
  }
  else if (iVar1 != 2) {
    ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x3c0);
  }
  group = (EC_GROUP *)0x0;
  ERR_put_error(0x10,0x91,0x7f,"ec_asn1.c",0x3d6);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)ECPKPARAMETERS_it);
LAB_081045b4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return group;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

