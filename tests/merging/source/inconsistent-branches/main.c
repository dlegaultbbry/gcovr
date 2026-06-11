#include <cstddef>
#include <cstdlib>

#ifdef BUILTIN_ALLOCA
#undef alloca
static bool alloca_pass;
void *my_alloca( size_t size )
{
    if( alloca_pass ) {
        return malloc( size );
    } else {
        return NULL;
    }
}
#define alloca my_alloca
#else
#undef alloca
#define alloca __builtin_alloca
#endif

int main(int argc, char* argv[])
{
    int length = argc;
    void *format_string = alloca( length + 1 ); // local stack copy of format string
    if( format_string == NULL || length == 0 ) {
        return 0;
    }
}
