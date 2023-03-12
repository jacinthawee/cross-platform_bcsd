
char * DSO_get_filename(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    return dso->filename;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x7f,0x43,"dso_lib.c",0x151);
  return (char *)0x0;
}

