
RSA * d2i_RSA_NET(RSA **a,uchar **pp,long length,cb *cb,int sgckey)

{
  undefined *puVar1;
  int **val;
  int iVar2;
  cb *pcVar3;
  RSA *pRVar4;
  uchar *local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_28 = *pp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  val = (int **)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_28,length,
                              (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  if (val == (int **)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,200,0x6f,"n_pkey.c",0x101);
    pRVar4 = (RSA *)0x0;
  }
  else {
    if (**val == 0xb) {
      iVar2 = (*(code *)PTR_strncmp_006aaa7c)("private-key",(*val)[2],0xb);
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)*val[1]);
        if (iVar2 == 5) {
          pcVar3 = (cb *)PTR_EVP_read_pw_string_006a8388;
          if (cb != (cb *)0x0) {
            pcVar3 = cb;
          }
          pRVar4 = (RSA *)d2i_RSA_NET_2_isra_0(a,val[1][1],val[1][1] + 8,pcVar3,sgckey);
          if (pRVar4 != (RSA *)0x0) {
            *pp = local_28;
          }
        }
        else {
          pRVar4 = (RSA *)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,200,0xa6,"n_pkey.c",0x10e);
        }
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        goto LAB_005683bc;
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,200,0x92,"n_pkey.c",0x108);
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
    pRVar4 = (RSA *)0x0;
  }
LAB_005683bc:
  if (local_24 == *(int *)puVar1) {
    return pRVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (RSA *)0x0;
}

