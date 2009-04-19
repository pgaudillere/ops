
using OPS;
namespace opstest
{
    public class ByteArrayDataPublisher 
        : Publisher 
    {


        public ByteArrayDataPublisher(Topic t)
            :base(t)
        {
            
            setObjectHelper(new ByteArrayDataHelper());

        }
        public void Write(ByteArrayData o) 
        {
            base.Write(o);
        }


    }
}