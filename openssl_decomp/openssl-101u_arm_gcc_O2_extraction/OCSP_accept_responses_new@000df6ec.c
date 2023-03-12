
X509_EXTENSION * OCSP_accept_responses_new(char **oids)

{
  _STACK *st;
  char *s;
  int n;
  _STACK *p_Var1;
  ASN1_OBJECT *data;
  char **ppcVar2;
  
  st = sk_new_null();
  if (st != (_STACK *)0x0) {
    if ((oids != (char **)0x0) && (s = *oids, s != (char *)0x0)) {
      ppcVar2 = oids + 1;
      do {
        n = OBJ_txt2nid(s);
        if ((n != 0) && (data = OBJ_nid2obj(n), data != (ASN1_OBJECT *)0x0)) {
          sk_push(st,data);
        }
        if (ppcVar2 == (char **)0x0) break;
        s = *ppcVar2;
        ppcVar2 = ppcVar2 + 1;
      } while (s != (char *)0x0);
    }
    p_Var1 = (_STACK *)X509V3_EXT_i2d(0x170,0,st);
    sk_pop_free(st,ASN1_OBJECT_free + 1);
    st = p_Var1;
  }
  return (X509_EXTENSION *)st;
}

