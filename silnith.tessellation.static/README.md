# silnith.tessellation.static

A trivial C++ library for tessellating arbitrary polygons into triangle fans.

## Quick-Start

```powershell
Install-Package silnith.tessellation.static
```

```cpp
#include <vector>
#include <silnith/tessellation/vertex.h>
#include <silnith/tessellation/polygon.h>
#include <silnith/tessellation/tessellator.h>

using namespace silnith::tessellation;

int main(int argc, char ** argv)
{
    tessellator tessellator;
    std::vector<polygon> result = tessellator.tessellate(polygon{ vertex{0, 0, 0}, vertex{0, 1, 0}, vertex{1, 1, 0}, vertex{1, 0, 0} });
}
```
