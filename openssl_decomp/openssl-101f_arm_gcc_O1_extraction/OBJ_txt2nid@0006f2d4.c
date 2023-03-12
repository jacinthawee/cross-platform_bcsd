
int OBJ_txt2nid(char *s)

{
  uint uVar1;
  int iVar2;
  int num;
  uchar *ptr;
  _LHASH *o;
  _LHASH *p_Var3;
  uchar *local_38;
  uchar **local_34;
  uchar *local_30 [2];
  uint local_28;
  
  uVar1 = OBJ_sn2nid(s);
  if ((uVar1 == 0) && (uVar1 = OBJ_ln2nid(s), uVar1 == 0)) {
    iVar2 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
    if (0 < iVar2) {
      num = ASN1_object_size(0,iVar2,6);
      ptr = (uchar *)CRYPTO_malloc(num,"obj_dat.c",0x1c4);
      if (ptr != (uchar *)0x0) {
        local_38 = ptr;
        ASN1_put_object(&local_38,0,iVar2,6,0);
        a2d_ASN1_OBJECT(local_38,iVar2,s,-1);
        local_30[0] = ptr;
        o = (_LHASH *)d2i_ASN1_OBJECT((ASN1_OBJECT **)0x0,local_30,num);
        CRYPTO_free(ptr);
        goto LAB_0006f35a;
      }
    }
    o = (_LHASH *)0x0;
  }
  else if (uVar1 < 0x398) {
    p_Var3 = *(_LHASH **)(&DAT_00140f90 + uVar1 * 0x18);
    o = (_LHASH *)(&nid_objs + uVar1 * 6);
    if (p_Var3 == (_LHASH *)0x0) {
      ERR_put_error(8,0x67,0x65,"obj_dat.c",0x12a);
      o = p_Var3;
    }
  }
  else {
    o = added;
    if (added != (_LHASH *)0x0) {
      local_34 = local_30;
      local_38 = (uchar *)0x3;
      local_28 = uVar1;
      o = (_LHASH *)lh_retrieve(added,&local_38);
      if (o == (_LHASH *)0x0) {
        ERR_put_error(8,0x67,0x65,"obj_dat.c",0x13b);
      }
      else {
        o = (_LHASH *)o->comp;
      }
    }
  }
LAB_0006f35a:
  iVar2 = OBJ_obj2nid((ASN1_OBJECT *)o);
  ASN1_OBJECT_free((ASN1_OBJECT *)o);
  return iVar2;
}

