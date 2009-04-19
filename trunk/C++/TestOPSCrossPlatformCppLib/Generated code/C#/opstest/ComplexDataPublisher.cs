
using OPS;
namespace opstest
{
    public class ComplexDataPublisher 
        : Publisher 
    {


        public ComplexDataPublisher(Topic t)
            :base(t)
        {
            
            setObjectHelper(new ComplexDataHelper());

        }
        public void Write(ComplexData o) 
        {
            base.Write(o);
        }


    }
}